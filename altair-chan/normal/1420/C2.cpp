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

const int N = 3e5 + 5;

int t;
int n,q;
int arr[N];

int gv(int i){
    if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
        return arr[i];
    }else if(arr[i] < arr[i-1] && arr[i] < arr[i+1]){
        return -arr[i];
    }
    return 0;
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
    while(t--){
        cin>>n>>q;
        arr[0] = arr[n+1] = 0;
        REP(i,1,n){
            cin>>arr[i];
        }

        ll ans = 0;
        REP(i,1,n){
            ans += gv(i);
            // printf("gv %d = %d\n",i,gv(i));
        }
        cout << ans << endl;

        REP(i,1,q){
            int l,r;
            cin>>l>>r;
            REP(j,-1,1){
                ans -= gv(l+j);
                if(r+j > l+1)ans -= gv(r+j);
            }
            swap(arr[l], arr[r]);
            REP(j,-1,1){
                ans += gv(l+j);
                if(r+j > l+1)ans += gv(r+j);
            }
            cout << ans << endl;
        }
    }

    return 0;
}