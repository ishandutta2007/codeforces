#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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
const int MAXN = 100010, LOG=20;

struct node{
	int cnt[26];
	node(){ memset(cnt, 0, sizeof(cnt));}
	node operator +(node x){
		node out;
		for (int i=0; i<26; i++) out.cnt[i]=x.cnt[i]+cnt[i];
		return out;
	}
} seg[MAXN<<2];

int n, m, k, u, v, x, y, t, l, r, ans;
int lazy[MAXN<<2];
string s;

node build(int id, int tl, int tr){
	if (tl==tr){
		seg[id].cnt[s[tl-1]-'a']=1;
		return seg[id];
	}
	int mid=(tl+tr)>>1;
	return seg[id]=build(id<<1, tl, mid) + build(id<<1 | 1, mid+1, tr);
}

void add_lazy(int id, int val){
	int len=0;
	for (int i=0; i<26; i++) len+=seg[id].cnt[i], seg[id].cnt[i]=0;
	seg[id].cnt[val]=len;
	lazy[id]=val;
}

void shift(int id){
	if (lazy[id]==-1) return ;
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=-1;
}

void update(int id, int tl, int tr, int l, int r, int val){
	if (r<tl || tr<l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, val);
	update(id<<1 | 1, mid+1, tr, l, r, val);
	seg[id]=seg[id<<1] + seg[id<<1 | 1];
}

node get(int id, int tl, int tr, int l, int r){
	if (r<tl || tr<l) return node();
	if (l<=tl && tr<=r) return seg[id];
	shift(id);
	int mid=(tl+tr)>>1;
	return get(id<<1, tl, mid, l, r) + get(id<<1 | 1, mid+1, tr, l, r);
}

void print(int id, int tl, int tr){
	if (tl==tr){
		for (int i=0; i<26; i++) if (seg[id].cnt[i]) cout<<(char)('a'+i);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	print(id<<1, tl, mid);
	print(id<<1 | 1, mid+1, tr);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(lazy, -1, sizeof(lazy));
	cin>>n>>m>>s;
	build(1, 1, n);
	while (m--){
		cin>>l>>r>>k;
		node tmp=get(1, 1, n, l, r);
		if (k) for (int i=0; i<26; l+=tmp.cnt[i++]) update(1, 1, n, l, l+tmp.cnt[i]-1, i);
		else for (int i=0; i<26; r-=tmp.cnt[i++]) if (tmp.cnt[i]) update(1, 1, n, r-tmp.cnt[i]+1, r, i);
	}
	print(1, 1, n);
	
	
	return 0;
}