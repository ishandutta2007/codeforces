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
typedef vector<vpi> vvpi;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e17
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

void a(){
    int x;
    cin>>x;
    string t;
    cin>>t;
    ll res = t.size();
    int l = 0;
    while(l != x){
        l++;
        ll n = res;
        int len = t.size();
        F0(k,(int) t[l-1] - (int) '1'){
            REP(i,l,len-1) {
                if(t.size() >= x) break;
                t.pb(t[i]);
            }
        }

        res += (ll) ((ll) t[l-1] - (ll) '1') * (ll) (n-l);
        res %= mod;
        res += mod;
        res %= mod;
    }
    cout<<res<<'\n';
}

/*
void filtrar(vpi& inter){
    if(inter.empty())
        return;
    vpi res;
    res.pb(inter[0]);
    F1(i,inter.size()-1) if(inter[i].F > res.back().F) res.pb(inter[i]);
    inter = res;
    res.clear();
    res.pb(inter[0]);
    F1(i,inter.size()-1) if(inter[i].S > res.back().S) res.pb(inter[i]);
    inter = res;
}

int l[500005];
int r[500005];
int x[500005];

ll f(){
    int n,k,m;
    cin>>n>>k>>m;
    F1(i,m) cin>>l[i]>>r[i]>>x[i];
    vpi events;
    F1(i,m) events.pb(mp(l[i],i));
    F1(i,m) events.pb(mp(r[i]+1,-i));
    sort(todo(events));
    reverse(todo(events));
    segmentSum magic(m+1);
    vi a(n+1);
    F1(i,n){
        while(!events.empty() and events.back().F == i){
            int pos = events.back().S;
            if(pos > 0) magic.asignar(pos, x[pos]);
            else magic.asignar(-pos,0);
            events.pop_back();
        }
        a[i] = magic.orr(1,n);
    }

    ll res = 1;
    F0(b,k){
        vi comienzo(n+1);
        F1(i,m){
            if(x[i] & (1<<b)) continue;
            maxi(comienzo[r[i]],l[i]);
        }
        vll dp(n+1);
        dp[0] = 1;
        ll suma = 1;
        int in = 0;
        int ult = 0;
        int j = 0;
        while(j < n){
            j++;
            if((a[j] & (1<<b)) == 0) {
                dp[j] = suma;
                suma += dp[j];
                suma %= mod;
            }

            REP(i,ult,comienzo[j]-1){
                suma -= dp[i];
                dp[i] = 0;
            }
            maxi(ult,comienzo[j]);
            suma %= mod;
            suma += mod;
            suma %= mod;
        }
        res *= suma;
        res %= mod;
    }
    cout<<res<<'\n';
    return res;
}*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../input.in","r",stdin);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) a();
    return 0;
}