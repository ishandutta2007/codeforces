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

void e(){
    int k1,k2,k3;
    cin>>k1>>k2>>k3;
    int n = k1+k2+k3;

    vi a(n+1);
    int aux;
    F0(i,k1) {
        cin>>aux;
        a[aux] = 1;
    }
    F0(i,k2) {
        cin>>aux;
        a[aux] = 2;
    }
    F0(i,k3) {
        cin>>aux;
        a[aux] = 3;
    }

    int i = n;
    int costoTotal = n - k1;
    int res = costoTotal;
    int cantDos = 0;
    int cantTres = 0;
    while(i > 0){
        if(a[i] == 1) costoTotal++;
        else costoTotal--;
        if(a[i] == 2) cantDos++;
        if(a[i] == 3) { cantTres++; costoTotal++;}
        if(cantTres > cantDos){
            costoTotal--;
            cantDos = 0;
            cantTres = 0;
        }
        mini(res,costoTotal);
        i--;
    }
    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    e();
    return 0;
}