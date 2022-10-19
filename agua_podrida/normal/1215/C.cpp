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
    int a1,a2,k1,k2,n;
    cin>>a1>>a2>>k1>>k2>>n;
    if(k1 > k2){
        swap(k1,k2);
        swap(a1,a2);
    }

    int res1 = 0;
    int aux = n;
    while(n - k1 >= 0 and res1 < a1){
        n -= k1;
        res1++;
    }
    while(n - k2 >= 0 and res1 < a1+a2){
        n -= k2;
        res1++;
    }

    n = aux;
    int res2 = 0;
    F0(i,a1) n -= k1-1;
    F0(i,a2) n -= k2-1;
    while(n>0 and res2 < a2) {n--; res2++;}
    while(n>0 and res2 < a1+a2) {n--; res2++;}

    cout<<min(res1,res2)<<' '<<max(res1,res2)<<'\n';
}

void b(){
    int n;
    cin>>n;
    vi A(n+1);
    F1(i,n) cin>>A[i];

    vll res(n+1);
    F1(i,n){
        if(A[i] > 0) res[i] += res[i-1] + 1;
        else res[i] = (ll) i - res[i-1] - 1;
    }

    ll suma = 0;
    F1(i,n) suma += res[i];
    ll negativos = (ll)n* (ll) (n+1)/ (ll) 2;
    negativos -= suma;
    cout<<negativos<<' '<<suma<<'\n';
}

void c(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int as = 0;
    F0(i,n) if(s[i] == 'a') as++;
    F0(i,n) if(t[i] == 'a') as++;
    if(as % 2 != 0){
        cout<<-1<<'\n';
        return;
    }

    vi aArriba;
    vi bArriba;
    F0(i,n) {
        if(s[i] == 'a' and t[i] == 'b') aArriba.pb(i+1);
        if(s[i] == 'b' and t[i] == 'a') bArriba.pb(i+1);
    }

    int k = 0;
    k += aArriba.size()/2;
    k += bArriba.size()/2;
    if(aArriba.size() % 2 == 1) k += 2;
    cout<<k<<'\n';
    int i = aArriba.size()-1;
    while(i >= 1){
        printf("%d %d\n",aArriba[i],aArriba[i-1]);
        i -= 2;
    }

    int j = bArriba.size()-1;
    while(j >= 1){
        printf("%d %d\n",bArriba[j],bArriba[j-1]);
        j -= 2;
    }

    if(i == 0){
        printf("%d %d\n",bArriba[0],bArriba[0]);
        printf("%d %d\n",bArriba[0],aArriba[0]);
    }
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    c();
}