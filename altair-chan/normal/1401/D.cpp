//pragma
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define REPP(i,a,b,d) for(int i=a;i<=b;i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a;i>=b;i-=d)
#define REV(i,a,b) REVV(i,a,b,1)

#define FOR(i,a) for(int i=0; i<a; i++)
#define FORD(i,a) for(int i=(int)a-1; i>=0; i--)

#define pb push_back
#define F first
#define S second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

#define getc getchar
template<typename T>
T getnum(){
	int sign = 1;
	T ret = 0;
	char c;

	do{
		c = getc();
	}while(c == ' ' || c == '\n');
	if(c == '-')sign = -1;
	else ret = c-'0';
	while(1){
		c = getc();
		if(c < '0' || c > '9')break;
		ret = 10*ret + c-'0';
	}
	return sign * ret;
}

inline void ini(int& x){
	x = getnum<int>();
}

inline void scani(int& x){
	scanf("%d",&x);
}

//end of macro

const ll MOD = 1e9 + 7;
inline ll addmod(ll a, ll b){
    if(a+b<MOD)return a+b;
    return a+b-MOD;
}
inline ll mulmod(ll a, ll b){
    return (a*b)%MOD;
}

const int N = 1e5 + 5;

int t;

int n;
vi lst[N];

int m;
int p[N];

int sz[N];
vector<ll> edges;
void dfs(int now, int par){
    sz[now] = 1;
    for(auto to : lst[now]){
        if(to == par)continue;
        dfs(to, now);
        sz[now] += sz[to];

        edges.pb((ll)sz[to] * (n - sz[to]));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>t;
    REP(z,1,t){
        cin>>n;
        REP(i,1,n)lst[i].clear();
        REP(i,2,n){
            int a,b;
            cin>>a>>b;
            lst[a].pb(b);
            lst[b].pb(a);
        }

        cin>>m;
        REP(i,1,m)cin>>p[i];
        sort(p+1, p+m+1);

        edges.clear();
        dfs(1, -1);

        sort(edges.begin(), edges.end());

        ll ans = 0;
        if(m >= edges.size()){
            int now = 1;
            for(int i=0; i+1<edges.size(); i++){
                ans = addmod(ans, mulmod(edges[i] % MOD, p[now++]));
            }
            int remain = 1;
            while(now <= m){
                remain = mulmod(remain, p[now++]);
            }
            ans = addmod(ans, mulmod(edges.back() % MOD, remain));
        }else{
            int now = m;
            for(int i=(int)edges.size()-1; i>=0; i--){
                if(now == 0)ans = addmod(ans, edges[i] % MOD);
                else ans = addmod(ans, mulmod(edges[i] % MOD, p[now--]));
            }
        }
        cout << ans << endl;
    }

    return 0;
}