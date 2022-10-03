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
const int inf=1e9;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 200010, LOG=20;

struct node{
	int M[5][5];
	node(int val=0){
		for (int i=0; i<=4; i++) for (int j=i; j<=4; j++) M[i][j]=inf;
		if (val) for (int i=0; i<=4; i++) M[i][i]=0;
	}
} seg[MAXN<<2];

node combine(node x, node y){
	node out(0);
	for (int i=0; i<=4; i++) for (int j=i; j<=4; j++) for (int k=i; k<=j; k++) out.M[i][j]=min(out.M[i][j], x.M[i][k] + y.M[k][j]);
	return out;
}

int n, m, k, u, v, x, y, t, l, r, ans;
int cnt[MAXN];
int last[MAXN][10];
string s;

node build(int id, int tl, int tr){
	if (tl==tr){
		for (int i=0; i<=4; i++) seg[id].M[i][i]=0;
		if (s[tl]=='2') seg[id].M[0][1]=seg[id].M[0][0]=1;
		if (s[tl]=='0') seg[id].M[1][2]=seg[id].M[1][1]=1;
		if (s[tl]=='1') seg[id].M[2][3]=seg[id].M[2][2]=1;
		if (s[tl]=='6') seg[id].M[3][4]=seg[id].M[3][3]=1;
		return seg[id];
	}
	int mid=(tl+tr)>>1;
	return seg[id]=combine(build(id<<1, tl, mid), build(id<<1 | 1, mid+1, tr));
}

node get(int id, int tl, int tr, int l, int r){
	if (r<tl || tr<l) return node(1);
	if (l<=tl && tr<=r) return seg[id];
	int mid=(tl+tr)>>1;
	return combine(get(id<<1, tl, mid, l, r), get(id<<1 | 1, mid+1, tr, l, r));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>s;
	s="."+s;
	build(1, 1, n);
	for (int i=1; i<=n; i++){
		cnt[i]=cnt[i-1] + (s[i]=='6');
		for (int j=0; j<=9; j++) last[i][j]=last[i-1][j];
		last[i][s[i]-'0']=i;
	}
	
	while (m--){
		cin>>l>>r;
		int pos=r;
		if (pos) pos=last[pos][7];
		if (pos) pos=last[pos][1];
		if (pos) pos=last[pos][0];
		if (pos) pos=last[pos][2];
		if (l>pos){
			cout<<-1<<'\n';
			continue ;
		}
		pos=last[r][7];
		ans=(cnt[r]-cnt[pos]) + get(1, 1, n, l, last[r][7]).M[0][3];
		cout<<ans-3<<'\n';
	}
	
	return 0;
}