#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

#define int ll

const int maxn = 1e6+5;
const int iinf = 1<<29;
const ll inf = 1ll<<60;
 ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll mpow(ll a, ll n){ // a^n % mod
	ll re=1;
	while (n>0){
		if (n&1) re = re*a %mod;
		a = a*a %mod;
		n>>=1;
	}
	return re;
}

ll inv (ll b){
	if (b==1) return b;
	return (mod-mod/b) * inv(mod%b) % mod;
}

struct node{
	node* c0 = nullptr; node * c1 = nullptr;
	int sz = 0;
};	

int nsz(node* nn){
	if (!nn) return 0;
	return nn->sz;
}

node* root = new node;

void add(int x){
	node* at = root;
	RREP(i,31){
		bool b = (x&(1<<i))/(1<<i);
		// debug(b);
		if (b){
			at->sz++;
			if (!at->c1) at->c1 = new node; 
			at = at->c1;
		}else{
			at->sz++;
			if (!at->c0) at->c0 = new node; 
			at = at->c0;
		}
	}
	at->sz++;
}

ll num(int k, int x){
	ll re = 0;
	node *at = root;
	int have = 0;
	RREP(i,31){
		if (at==nullptr) break;
		bool b = (k&(1<<i))/(1<<i);
		int xx = (1<<i);
		bool bx = (x&(1<<i))/(1<<i);
		// debug(b);
		if (have + xx >= k){
			if (bx) re+=nsz(at->c0), at = at->c1;
			else re+=nsz(at->c1), at = at->c0;
		}
		else{
			have+=xx;
			if (bx) at = at->c0;
			else at = at->c1;
		}
	}
	if (have>=k) re+=nsz(at);
	return re;
}

int px[maxn];

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, k; cin>>n>>k;
    add(0);
    ll re = 0;
    REP(i,n){
    	int tmp; cin>>tmp; px[i+1]= px[i] ^ tmp;
    	int tn = num(k,px[i+1]);
    	// debug(tn);
    	re+=tn;
    	add(px[i+1]);
    }
    cout<<re<<endl;
}