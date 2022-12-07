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

const int N = 1<<18;

int n,nn,q;
int arr[N+5];

int flip[22];

ll tree[4*N];
void build(int idx, int left, int right){
    if(left == right){
        tree[idx] = arr[left];
    }else{
        int mid = (left+right)/2;
        build(idx<<1, left, mid);
        build(idx<<1|1, mid+1, right);
        tree[idx] = tree[idx<<1] + tree[idx<<1|1];
    }
}
void update(int idx, int left, int right, int level, int x, ll v){
    if(left == right){
        tree[idx] = v;
    }else{
        int mid = (left+right)/2;
        int s = right-mid;
        if(x <= mid){
            if(!flip[level]){
                update(idx<<1, left, mid, level-1, x, v);
            }else{
                update(idx<<1|1, mid+1, right, level-1, x+s, v);
            }
        }else{
            if(!flip[level]){
                update(idx<<1|1, mid+1, right, level-1, x, v);
            }else{
                update(idx<<1, left, mid, level-1, x-s, v);
            }
        }
        tree[idx] = tree[idx<<1] + tree[idx<<1|1];
    }
}
ll query(int idx, int left, int right, int level, int l, int r){
    if(left >= l && right <= r){
        // printf("take %d-%d = %lld\n",left,right,tree[idx]);
        return tree[idx];
    }else if(right < l || left > r){
        return 0;
    }else{
        int mid = (left+right)/2;
        int s = right-mid;
        if(!flip[level]){
            return query(idx<<1, left, mid, level-1, l, r)
                + query(idx<<1|1, mid+1, right, level-1, l, r);
        }else{
            int l1 = left, r1 = mid;
            int l2 = mid+1, r2 = right;
            l1 = max(l1, l);
            l2 = max(l2, l);
            r1 = min(r1, r);
            r2 = min(r2, r);
            // printf("q %ld-%d -> %d-%d, %d-%d\n",l,r,l1,r1,l2,r2);
            return query(idx<<1, left, mid, level-1, l2-s, r2-s)
                + query(idx<<1|1, mid+1, right, level-1, l1+s, r1+s);
        }
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

    cin>>n>>q;
    nn = 1<<n;
    REP(i,1,nn)cin>>arr[i];

    build(1, 1, nn);

    REP(i,1,q){
        int op,a,b;
        cin>>op;
        if(op == 1){
            cin>>a>>b;
            update(1, 1, nn, n, a, b);
        }else if(op == 2){
            cin>>a;
            REV(i,a,1)flip[i] ^= 1;
        }else if(op == 3){
            cin>>a;
            flip[a+1] ^= 1;
        }else{
            cin>>a>>b;
            cout << query(1, 1, nn, n, a, b) << endl;
        }
    }

    return 0;
}