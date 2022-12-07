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

#define ALL(v) v.begin(), v.end()

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

const int N = 1e6 + 5;

int n;
ll r1, r2, r3, d;
int a[N];
ll dist[N][3]; // level, unfinished business (0 -> ok, 1 -> 1 level before, 2 -> too far)
// 0 plain
// 1 includes +d+r1
// 2 includes +d+d+d... +r1

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n>>r1>>r2>>r3>>d;
    REP(i,1,n)cin>>a[i];

    dist[1][0] = 0;
    dist[1][1] = dist[1][2] = INF;
    REP(i,1,n-1){
        FOR(j,3)dist[i+1][j] = INF;

        // go back 1 level and clear immediately
        dist[i][0] = min(dist[i][0], dist[i][1] + d); // note +d+r1 is already in dist[i][1]
        // i mean, technically, 2 includes 1
        dist[i][2] = min(dist[i][2], dist[i][1]);

        ll effort, move;
        // clear level
        effort = a[i] * r1 + r3;
        dist[i+1][0] = min(dist[i+1][0], dist[i][0] + effort + d);
        dist[i+1][2] = min(dist[i+1][2], dist[i][1] + effort + d + d);
        dist[i+1][2] = min(dist[i+1][2], dist[i][2] + effort + d + d);

        // damage boss
        effort = min(r2, (a[i]+1) * r1);
        dist[i+1][1] = min(dist[i+1][1], dist[i][0] + effort + d + d + r1);
        dist[i+1][0] = min(dist[i+1][0], dist[i][1] + effort + d + r1 + d);
        dist[i+1][2] = min(dist[i+1][2], dist[i][2] + effort + d + d + r1);
    }

    // REP(i,1,n){
    //     FOR(j,3)printf("%lld ",dist[i][j]);
    //     printf("\n");
    // }

    ll ans = INF;
    {
        ll effort, move;
        // clear level
        effort = a[n] * r1 + r3;
        ans = min(ans, dist[n][0] + effort);
        ans = min(ans, dist[n][1] + effort);
        ans = min(ans, dist[n][2] + effort);

        // damage boss
        effort = min(r2, (a[n]+1) * r1);
        ans = min(ans, dist[n][0] + effort + d + d + r1);
        ans = min(ans, dist[n][1] + effort + d + r1);
        ans = min(ans, dist[n][2] + effort + d + d + r1);
    }
    cout << ans << endl;

    return 0;
}