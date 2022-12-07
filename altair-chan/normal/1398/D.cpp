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

const int N = 205;

int nr,ng,nb,n;
vi a,b,c;

int dp[N][N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>nr>>ng>>nb;
    n = nr+ng+nb;
    REP(i,1,nr){
        int x; cin>>x;
        a.pb(x);
    }
    REP(i,1,ng){
        int x; cin>>x;
        b.pb(x);
    }
    REP(i,1,nb){
        int x; cin>>x;
        c.pb(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    int ans = 0;
    dp[0][0][0] = 0;
    REP(i,0,nr){
        REP(j,0,ng){
            REP(k,0,nb){
                int res = 0;

                // skip i
                if(i > 0){
                    res = max(res, dp[i-1][j][k]);
                }

                // skip j
                if(j > 0){
                    res = max(res, dp[i][j-1][k]);
                }

                // skip k
                if(k > 0){
                    res = max(res, dp[i][j][k-1]);
                }

                // take i j
                if(i > 0 && j > 0){
                    res = max(res, dp[i-1][j-1][k] + a[i-1] * b[j-1]);
                }

                // take j k
                if(j > 0 && k > 0){
                    res = max(res, dp[i][j-1][k-1] + b[j-1] * c[k-1]);
                }

                // take i k
                if(i > 0 && k > 0){
                    res = max(res, dp[i-1][j][k-1] + a[i-1] * c[k-1]);
                }

                dp[i][j][k] = res;
                ans = max(ans, res);
            }
        }
    }

    cout << ans << endl;

    return 0;
}