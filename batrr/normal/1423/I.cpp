#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, K = 16, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, q, k, a[N], b[N], A[K][N], B[K][N];
pii t[N << 2][2]; 
void add_A(int l, int r, int x){
	for(int i = 0; i < K; i++){
		if((x >> i) & 1){
			A[i][l]++;
			A[i][r + 1]--;			
		}
	}
}
void add_B(int l, int r, int x){
	for(int i = 0; i < K; i++){
		if((x >> i) & 1){
			B[i][l]++;
			B[i][r + 1]--;			
		}
	}
}   
void add_interval(ll l, ll r, int x){
	if(l > r)
		return;
	int bl = l >> k;
	int br = r >> k;
	int kk = (1 << k) - 1;
	if(bl == br){
		add_A(l & kk, r & kk, x);
	}else{
		if(bl + 1 < br){
			add_A(0, kk, x);
		}else{
			add_A(l & kk, kk, x);
			add_A(0, r & kk, x);
		}
	}
	add_B(bl, br, x);
}

void build(int v, int tl, int tr){
	if(tl == tr){                
		t[v][0] = {a[tl], a[tl]};
		t[v][1] = {b[tl], b[tl]};
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);            
	
	t[v][0].f = (t[v << 1][0].f & t[v << 1 | 1][0].f);
	t[v][0].s = (t[v << 1][0].s | t[v << 1 | 1][0].s);
	
	t[v][1].f = (t[v << 1][1].f & t[v << 1 | 1][1].f);
	t[v][1].s = (t[v << 1][1].s | t[v << 1 | 1][1].s);
}
pii get(int v, int tl, int tr, int l, int r, int kk){
	if(r < tl || tr < l)
		return {(1 << K) - 1, 0};	
	if(l <= tl && tr <= r)
		return t[v][kk];
	int tm = (tl + tr) >> 1;
	pii a = get(v << 1, tl, tm, l, r, kk);
	pii b = get(v << 1 | 1, tm + 1, tr , l, r, kk);
	return {a.f & b.f, a.s | b.s};
}
void no(){
	printf("impossible");
	exit(0);
}
bool is_submask(int sub, int mask){
	return (sub & mask) == sub; 
}
void check(int l, int r, int bl, int br, int x){
	if(l > r || bl > br)
		return;
	pii a = get(1, 0, (1 << k) - 1, l, r, 0);	
	pii b = get(1, 0, (1 << k) - 1, bl, br, 1);	
	if(!is_submask(x, a.f))
		no();		
	if(!is_submask(x, b.f))
		no();		
	if((a.s & b.s) != x)
		no();	
}
void check_interval(ll l, ll r, int x){
	if(l > r)
		return;
	int bl = l >> k;
	int br = r >> k;
	int kk = (1 << k) - 1;
	if(bl == br){
		check(l & kk, r & kk, bl, br, x);
	}else{
		check(l & kk, kk, bl, bl, x);
		check(0, r & kk, br, br, x);
		check(0, kk, bl + 1, br - 1, x);
	}
}
int main()
{
	scanf("%d%d", &k, &q);
	vector< pair< ll, pll > > v;
	for(int i = 0; i < q; i++){
		ll l, r, x;
		scanf("%lld%lld%lld", &l, &r, &x);
		v.pb({x, {l, r}});
	}
	sort(v.begin(), v.end());
	for(int i = 0, j = 0; i < v.size(); i = j){
		while(j < v.size() && v[i].f == v[j].f)
			j++;
		ll R = -1;
		for(int q = i; q < j; q++){
			ll l = v[q].s.f;
			ll r = v[q].s.s;
			int x = v[q].f;
			add_interval(max(R, l), r, x);
			R = max(R, r);
		}
	}
	for(int i = 0; i < K; i++){
		for(int j = 1; j < (1 << k); j++){
			A[i][j] += A[i][j - 1];		
			B[i][j] += B[i][j - 1];		
		}                   
		for(int j = 0; j < (1 << k); j++){
			if(A[i][j] > 0)
				a[j] |= (1 << i);	
			if(B[i][j] > 0)
				b[j] |= (1 << i);	
		}											
	}
	build(1, 0, (1 << k) - 1);
	for(int i = 0, j = 0; i < v.size(); i = j){
		while(j < v.size() && v[i].f == v[j].f)
			j++;
		ll R = -1;
		for(int q = i; q < j; q++){
			ll l = v[q].s.f;
			ll r = v[q].s.s;
			int x = v[q].f;
			check_interval(max(R, l), r, x);
			R = max(R, r);
		}
	}
	printf("possible\n");
	for(int i = 0; i < (1 << k); i++)
		printf("%d ", a[i]); 	
	printf("\n");	
	for(int i = 0; i < (1 << k); i++)
		printf("%d ", b[i]); 	
	printf("\n");	
}