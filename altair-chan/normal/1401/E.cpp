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

const int N = 1e5 + 5;
const int M = 1e6;

int bitt[M + 5];
void update(int x, int v){
    REPP(i,x,M,i&-i) bitt[i] += v;
}
int query(int x){
    int ret = 0;
    REVV(i,x,1,i&-i) ret += bitt[i];
    return ret;
}
int query(int l, int r){
    return query(r) - query(l-1);
}

int n,m;
ll ans = 1;

vii lf;
vii rg;

vector<pair<int,pii> > vec;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n>>m;
    REP(i,1,n){
        int y,l,r;
        cin>>y>>l>>r;
        if(l == 0 && r == M) ans++;
        if(l == 0)  lf.pb({r, y});
        else rg.pb({l, y});
    }
    sort(lf.begin(), lf.end());
    sort(rg.begin(), rg.end());

    FOR(i,lf.size()){
        update(lf[i].S, 1);
    }

    REP(i,1,m){
        int x, l, r;
        cin>>x>>l>>r;
        vec.pb({x, {l, r}});
    }
    sort(vec.begin(), vec.end());

    int pl = 0, pr = 0;
    for(auto item : vec){
        int x = item.F;
        int l = item.S.F;
        int r = item.S.S;
        if(l == 0 && r == M) ans++;

        while(pl < lf.size() && lf[pl].F < x){
            update(lf[pl].S, -1);
            pl++;
        }
        while(pr < rg.size() && rg[pr].F <= x){
            update(rg[pr].S, 1);
            pr++;
        }

        ans += query(l, r);
    }
    cout << ans << endl;

    return 0;
}