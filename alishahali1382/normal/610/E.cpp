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
const int MAXN = 200010, K=10;

struct node{
	int cnt[K][K];
	char lazy, first, last;
	void combine(node &n1, node &n2){
		for (int i=0; i<K; i++) for (int j=0; j<K; j++) cnt[i][j]=n1.cnt[i][j]+n2.cnt[i][j];
		cnt[n1.last-'a'][n2.first-'a']++;
		lazy=0;
		first=n1.first;
		last=n2.last;
	}
} seg[MAXN<<2];

int n, m, k, u, v, x, y, t, a, b, ans;
string s;
char ch;

void build(int id, int tl, int tr){
	if (tr-tl==1){
		seg[id].first=seg[id].last=s[tl];
		return ;
	}
	int mid=(tl+tr)>>1;
	build(id<<1, tl, mid);
	build(id<<1 | 1, mid, tr);
	seg[id].combine(seg[id<<1], seg[id<<1 | 1]);	
}

void add_lazy(int id, int len, char lz){
	memset(seg[id].cnt, 0, sizeof(seg[id].cnt));
	seg[id].cnt[lz-'a'][lz-'a']=len-1;
	seg[id].first=seg[id].last=seg[id].lazy=lz;
}

void shift(int id, int tl, int tr){
	if (!seg[id].lazy) return ;
	int mid=(tl+tr)>>1;
	add_lazy(id<<1, mid-tl, seg[id].lazy);
	add_lazy(id<<1 | 1, tr-mid, seg[id].lazy);
	seg[id].lazy=0;
}

void update(int id, int tl, int tr, int l, int r, char ch){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, tr-tl, ch);
		return ;
	}
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, ch);
	update(id<<1 | 1, mid, tr, l, r, ch);
	seg[id].combine(seg[id<<1], seg[id<<1 | 1]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	cin>>s;
	build(1, 0, n);
	while (m--){
		cin>>t;
		if (t==1){
			cin>>x>>y>>ch;
			update(1, 0, n, x-1, y, ch);
			continue ;
		}
		cin>>s;
		ans=1;
		for (int i=0; i<k; i++) for (int j=0; j<=i; j++) ans+=seg[1].cnt[s[i]-'a'][s[j]-'a'];
		cout<<ans<<'\n';
		//for (int i=0; i<k; i++) for (int j=0; j<=i; j++) cerr<<s[i]<<", "<<s[j]<<"-->"<<seg[1].cnt[s[i]-'a'][s[j]-'a']<<endl;
	}
	
	return 0;
}