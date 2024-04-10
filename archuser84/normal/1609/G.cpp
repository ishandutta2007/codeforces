///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

#define int ll

const int N = 105, M = 131'072;
int n, m;

int a[N], b[M];
int b0, suma, sumb;

int sum[M<<1];
int lzy[M<<1];
int mx[M<<1];

static inline void tag(int i, int x, int len){sum[i]+=x*len; mx[i]+=x; lzy[i]+=x;}
static inline void merge(int i){
	sum[i] = sum[2*i+1]+sum[2*i+2];
	mx[i] = mx[2*i+2];
}
static inline void ppg(int i, int len){
	if(lzy[i]){
		tag(2*i+1,lzy[i],len/2);
		tag(2*i+2,lzy[i],(len+1)/2);
		lzy[i]=0;
	}
}

/*int get_sum(int l, int r, int i=0, int b=1, int e=m)
{
	if(l <= b && e <= r) return sum[i];
	if(r <= b || e <= l) return 0;
	ppg(i,e-b);
	int ans = 0;
	return get_sum(l,r,2*i+1,b,(b+e)/2)+get_sum(l,r,2*i+2,(b+e)/2,e);
}*/

pair<int,int> get_bin(int x, int i=0, int b=1, int e=m)
{
	if(mx[i]<=x) return {e,sum[i]};
	if(e-b==1) return {b,0};
	ppg(i,e-b);
	if(mx[2*i+1]<=x) {auto [j,s] = get_bin(x,2*i+2,(b+e)/2,e); return {j,s+sum[2*i+1]};}
	else             return get_bin(x,2*i+1,b,(b+e)/2);
}

void add(int l, int r, int x, int i=0, int b=1, int e=m)
{
	if(l <= b && e <= r) return tag(i,x,e-b);
	if(r <= b || e <= l) return;
	ppg(i,e-b);
	add(l,r,x,2*i+1,b,(b+e)/2);
	add(l,r,x,2*i+2,(b+e)/2,e);
	merge(i);
}

void init(int i=0, int b=1, int e=m)
{
	if(e-b==1) {sum[i]=mx[i]=::b[b]-::b[b-1]; return;}
	init(2*i+1,b,(b+e)/2);
	init(2*i+2,(b+e)/2,e);
	merge(i);
}

void Qa(int k, int d){Loop(i,0,k) a[n-k+i] += (i+1)*d;}
void Qb(int k, int d){
	sumb += k*(k+1)/2 * d;
	if(k==m){b0+=d; --k;}
	add(m-k,m,d);
}

int solve(){
	int ans = sumb;
	//cout << ans << '\n';
	int lst = 0;
	Loop(i,1,n){
		int x = a[i]-a[i-1];
		auto [j,s] = get_bin(x); --j;
		ans += b0+s;
		//cout << j << "!\n";
		//cout << get_sum(1,j+1) << '\n';
		ans += a[i-1]*(j-lst+1);
		//cout << ans << '\n';
		lst = j;
		//cout << ans << '\n';
	}
	ans += (m-lst)*a[n-1];
	//cout << ans << '\n';
	return ans;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int q;
	cin >> n >> m >> q;
	Loop(i,0,n) cin >> a[i], suma += a[i];
	Loop(i,0,m) cin >> b[i], sumb += b[i];
	b0 = b[0];
	init();
	//cout << mx[0] << '\n';
	while(q--)
	{
		int t, k, d;
		cin >> t >> k >> d;
		t==1?Qa(k,d):Qb(k,d);
		cout << solve() << '\n';
	}
}