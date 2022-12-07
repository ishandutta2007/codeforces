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

const int N = 2e5 + 5;

int n;
int tp[N], d[N];

vii spells;
map<pii,int>mapper;

struct _data{
    ll sum;
    int cnt;
    int t1;
    _data(int sum=0, int cnt=0, int t1=0) : sum(sum), cnt(cnt), t1(t1){
    }
};

_data combine(_data a, _data b){
    _data ret;
    ret.sum = a.sum + b.sum;
    ret.cnt = a.cnt + b.cnt;
    ret.t1 = a.t1 + b.t1;
    return ret;
}

_data tree[4*N];
void update(int idx, int left, int right, int x, _data v){
    if(left == right){
        tree[idx] = v;
    }else{
        int mid = (left+right)/2;
        if(x <= mid) update(idx<<1, left, mid, x, v);
        else update(idx<<1|1, mid+1, right, x, v);
        tree[idx] = combine(tree[idx<<1], tree[idx<<1|1]);
    }
}

// query sum of k highest
_data query(int idx, int left, int right, int k){
    if(k == 0)return 0;
    else if(left == right){
        return tree[idx];
    }else{
        int mid = (left+right)/2;
        if(tree[idx<<1|1].cnt >= k){
            return query(idx<<1|1, mid+1, right, k);
        }else{
            return combine(tree[idx<<1|1], query(idx<<1, left, mid, k-tree[idx<<1|1].cnt));
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

    cin>>n;
    REP(i,1,n){
        cin>>tp[i]>>d[i];
        if(d[i] > 0){
            spells.pb({d[i], tp[i]});
        }
    }

    sort(spells.begin(), spells.end());
    FOR(i,spells.size()){
        mapper[spells[i]] = i;
    }

    int s = spells.size();
    int curr = 0;
    int cl = 0;

    REP(i,1,n){
        int pos = mapper[{abs(d[i]), tp[i]}];
        if(tp[i] == 1){
            if(d[i] > 0) cl++;
            else cl--;
        }
        if(d[i] > 0){
            curr++;
            update(1, 0, s-1, pos, {d[i], 1, tp[i]});
        }else{
            curr--;
            update(1, 0, s-1, pos, {0, 0, 0});
        }

        int taker = min(cl, curr-1);
        ll csum = tree[1].sum;
        // printf("csum %lld, curr %d, taker %d\n",csum,curr,taker);
        if(taker == 0){
            cout << csum << endl;
        }else{
            _data datar = query(1, 0, s-1, taker);
            if(datar.t1 != cl){
                cout << csum + datar.sum << endl;
            }else{
                taker--;
                _data datar2 = query(1, 0, s-1, taker);
                _data datar3 = query(1, 0, s-1, taker+2);
                int hf = datar3.sum - datar.sum;
                cout << csum + datar2.sum + hf << endl;
            }
        }
    }

    return 0;
}