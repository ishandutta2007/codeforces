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

const int N = 27;

int n, q;
ll arr[N][N];
ll lo[N][N], hi[N][N];

stack<pii>stk;

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    // #define endl '\n'
    // cout.setf(ios::fixed);
    // cout.setf(ios::showpoint);
    // cout.precision(10);

    cin>>n;
    arr[1][1] = 0;
    lo[1][1] = hi[1][1] = 0;
    REP(i,1,n){
        REP(j,1,n){
            if(i == 1 && j == 1)continue;
            if(i == 1)arr[i][j] = lo[i][j] = hi[i][j] = 0;
            else{
                lo[i][j] = lo[i-1][j];
                hi[i][j] = (j > 1) ? hi[i][j-1] : hi[i-1][j];
                ll raise = hi[i-1][j+1] + 1 - lo[i][j];

                arr[i][j] = raise;
                lo[i][j] += raise;
                hi[i][j] += raise;
            }
        }
    }

    // REP(i,1,n){
    //     REP(j,1,n){
    //         printf("%d(%d,%d) ",arr[i][j],lo[i][j],hi[i][j]);
    //     }
    //     printf("\n");
    // }

    REP(i,1,n){
        REP(j,1,n){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cin>>q;
    while(q--){
        ll d;
        cin>>d;
        int x = n, y = n;
        while(1){
            stk.push({x, y});
            if(x == 1 && y == 1)break;
            if(x == 1){
                y--;
            }else if(y == 1){
                x--;
            }else{
                d -= arr[x][y];
                if(d <= hi[x-1][y])x--;
                else y--;
            }
        }
        while(!stk.empty()){
            cout << stk.top().F << " " << stk.top().S << endl;
            stk.pop();
        }
    }

    return 0;
}