#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<bool> vbool;
typedef unsigned int uint;

template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define F first
#define S second
#define INF 10000000
#define todo(v) v.begin(),v.end()

void a(){
    ll n,k;
    int m;
    cin>>n>>m>>k;
    vll specials(m);
    F0(i,m) cin>>specials[i];
    reverse(todo(specials));
    ll borrados = 0;
    int res = 0;
    while(!specials.empty()){
        ll pagina = (specials.back()-borrados-1) / k;
        ll masBorrados = 0;
        int i = specials.size()-1;
        while(i >= 0 and (specials[i]-borrados-1) / k == pagina) {
            specials.pop_back();
            masBorrados++;
            i--;
        }
        borrados += masBorrados;
        res++;
    }
    cout<<res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("../subtle_sabotage.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    a();
    return 0;
}