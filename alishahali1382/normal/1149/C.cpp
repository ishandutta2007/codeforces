#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 200010, LOG=20;

struct node{
	int a, b, c, ab, bc, abc;
	node(int x=0) : a(x), b(-2*x), c(x), ab(-x), bc(-x), abc(0){}
} seg[MAXN<<2];

node combine(node x, node y){
	node out;
	out.a=max(x.a, y.a);
	out.b=max(x.b, y.b);
	out.c=max(x.c, y.c);
	out.ab=max(max(x.ab, y.ab), x.a+y.b);
	out.bc=max(max(x.bc, y.bc), x.b+y.c);
	out.abc=max(max(x.abc, y.abc), max(x.ab+y.c, x.a+y.bc));
	return out;
}

int n, m, k, u, v, x, y, t, a, b, ans;
int lazy[MAXN<<2];
string s;

void add_lazy(int id, int val){
	seg[id].a+=val;
	seg[id].b-=2*val;
	seg[id].c+=val;
	seg[id].ab-=val;
	seg[id].bc-=val;
	lazy[id]+=val;
}

void shift(int id){
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}

void update(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, val);
	update(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=combine(seg[id<<1], seg[id<<1 | 1]);
}

int f(char ch){
	if (ch=='(') return 1;
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>s;
	n=2*n-2;
	for (int i=0; i<n; i++) update(1, 0, n, i, n, f(s[i]));
	cout<<seg[1].abc<<'\n';
	while (m--){
		cin>>a>>b;
		a--;
		b--;
		if (a>b) swap(a, b);
		if (s[a]!=s[b]){
			swap(s[a], s[b]);
			update(1, 0, n, a, b, 2*f(s[a]));
		}
		cout<<seg[1].abc<<'\n';
	}
	
	return 0;
}
/*
5 1
(((())))
4 5

*/