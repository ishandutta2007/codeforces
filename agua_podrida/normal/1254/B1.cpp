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
    int r,c,k;
    cin>>r>>c>>k;
    vector<string> farm(r);
    F0(i,r) cin>>farm[i];
    int arroz = 0;
    F0(i,r) F0(j,c) if(farm[i][j] == 'R') arroz++;

    int paracu = arroz / k;
    int masun = arroz % k;

    vector<string> res = farm;
    char pollo = 'a';
    int i = 0;
    int j = 0;
    F0(p,k){
        if(p == 26) pollo = 'A';
        if(p == 52) pollo = '0';

        int faltan = paracu;
        if(p < masun) faltan++;
        while(faltan > 0) {
            res[i][j] = pollo;
            if (farm[i][j] == 'R') faltan--;

            if (i % 2 == 0) j++;
            else j--;
            if (j == c) {
                j--;
                i++;
            }
            else if (j == -1) {
                j++;
                i++;
            }
        }
        pollo++;
    }

    pollo--;
    while(i < r){
        res[i][j] = pollo;
        if(i%2 == 0) j++;
        else j--;
        if(j == c) {j--; i++;}
        else if(j == -1) {j++; i++;}
    }

    F0(i,r) cout<<res[i]<<'\n';
}

void b1(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    int total = 0;
    F0(i,n) total += a[i];

    if(total == 1){
        cout<<-1<<'\n';
        return;
    }

    vi factorizacion;
    int factor = 2;
    while(total > 1){
        if(total % factor == 0) {
            while(total % factor == 0) total /= factor;
            factorizacion.pb(factor);
        }
        else factor++;
    }
    ll costoMin = (ll) n * (ll) n;
    F0(c, factorizacion.size()){
        int cand = factorizacion[c];
        ll costo = 0;
        int junte = 0;
        int i = 0;
        while(i < n){
            junte = 0;
            vi posiciones(cand);
            while(junte < cand){
                while(i < n and a[i] == 0) i++;
                posiciones[junte] = i;
                junte++;
                i++;
            }
            int m = cand/2;
            F0(p,cand) costo += (ll) abs(posiciones[p]-posiciones[m]);
            while(i < n and a[i] == 0) i++;
        }
        mini(costoMin,costo);
    }
    cout<<costoMin<<'\n';
}

int main() {
    b1();
    return 0;
}