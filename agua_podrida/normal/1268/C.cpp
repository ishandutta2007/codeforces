#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
ll mod = 1000000007;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

void a(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vi in(n);
    F0(i,n) in[i] = (int) s[i] - (int) '0';
    cout<<n<<'\n';

    vi out(n);
    int i = 0;
    while(i < k) {
        out[i] = in[i];
        i++;
    }
    while(i < n){
        out[i] = out[i-k];
        i++;
    }

    if(out >= in) {
        F0(i,n) cout<<out[i];
        cout<<'\n';
        return;
    }

    i = k-1;
    while(out[i] == 9){
        out[i] = 0;
        i--;
    }
    out[i]++;
    i = k;
    while(i < n){
        out[i] = out[i-k];
        i++;
    }
    F0(i,n) cout<<out[i];
    cout<<'\n';
}

void b(){
    int n;
    cin>>n;
    vll a(n);
    F0(i,n) cin>>a[i];
    ll blancas = 0;
    ll negras = 0;
    F0(i,n){
        blancas += a[i]/2;
        negras += a[i]/2;
        if(a[i] % 2 == 1){
            if(i%2 == 0) blancas++;
            else negras++;
        }
    }
    cout<<min(blancas,negras)<<'\n';
}

struct segmentSum{
    segmentSum(vi& values);
    segmentSum(int nn);

    void asignar(int i, ll x);

    ll sumr(int a, int b);

    int n;
    vll tree;
};

segmentSum::segmentSum(int nn) {
    n = nn;
    tree = vll(2*n);
}

segmentSum::segmentSum(vi& values) {
    n = values.size();
    tree = vll(2*n);
    F0(i,n) tree[n+i] = values[i];
    F1R(i,n-1) tree[i] = tree[2*i] + tree[2*i+1];
}

void segmentSum::asignar(int i, ll x) {
    i += n;
    tree[i] = x;
    for(i /= 2; i >= 1; i /= 2) tree[i] = tree[2*i] + tree[2*i+1];
}

ll segmentSum::sumr(int a, int b) {
    a += n; b += n;
    int sum = 0;
    while(a <= b){
        if(a % 2 == 1) sum += tree[a++];
        if(b % 2 == 0) sum += tree[b--];
        a /= 2; b /= 2;
    }
    return sum;
}

void c(){
    int n;
    cin>>n;
    vi p(n+1);
    F1(i,n) cin>>p[i];

    vi pos(n+1);
    F1(i,n) pos[p[i]] = i;

    segmentSum tree(n+1);

    set<int> adentro;

    ll invertidos = 0;
    F1(i,n){
        invertidos += tree.sumr(pos[i]+1,n);
        tree.asignar(pos[i],1);
        adentro.insert(pos[i]);
    }

    ll separar = 0;
    int pder = (n+1)/2;
    int pizq = pder;
    if(n%2 == 0) pizq++;
    vll res(n+1);
    F1R(i,n){
        if(i == 1) break;
        res[i] = invertidos+separar;
        tree.asignar(pos[i],0);
        invertidos -= tree.sumr(pos[i]+1,n);
        if(pos[i] == pder and pos[i] == pizq){
            auto it = adentro.find(pos[i]);
            it--;
            pder = *it;
            it++; it++;
            pizq = *it;
            separar += tree.sumr(pos[i],n);
        }
        else if(pos[i] > pder){
            ll reducen = pos[i] - pder;
            reducen -= tree.sumr(pder,pos[i]);
            separar -= reducen;
            separar += tree.sumr(pos[i],n);
            //actualizar pder pizq
            if(i == 2) continue;
            if(pder != pizq){
                pizq = pder;
            }
            else{
                auto it = adentro.find(pder);
                it--;
                pder = *it;
            }
        }
        else if(pos[i] < pizq){
            ll reducen = pizq - pos[i];
            reducen -= tree.sumr(pos[i],pizq);
            separar -= reducen;
            separar += tree.sumr(1,pos[i]);
            //actualizar pder pizq
            if(i == 2) continue;
            if(pder != pizq){
                pder = pizq;
            }
            else {
                auto it = adentro.find(pizq);
                it++;
                pizq = *it;
            }
        }
        adentro.erase(pos[i]);
    }
    res[1] = 0;
    F1(i,n) cout<<res[i]<<' ';
    cout<<'\n';
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    c();
    return 0;
}