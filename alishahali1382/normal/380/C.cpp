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
const int MAXN = 1000010, LOG=20;

struct node{
	int ans, co, cc;
} seg[MAXN<<2];

node combine(node i, node j){
	int mn=min(i.co, j.cc);
	return {i.ans+j.ans+mn, i.co+j.co-mn, i.cc+j.cc-mn};
}

int n, m, k, u, v, x, y, t, l, r, ans;
string s;

node build(int id, int tl, int tr){
	if (tl==tr) return seg[id]={0, s[tl-1]=='(', s[tl-1]==')'};
	int mid=(tl+tr)>>1;
	return seg[id]=combine(build(id<<1, tl, mid), build(id<<1 | 1, mid+1, tr));
}

node get(int id, int tl, int tr, int l, int r){
	if (r<tl || tr<l) return {0, 0, 0};
	if (l<=tl && tr<=r) return seg[id];
	int mid=(tl+tr)>>1;
	return combine(get(id<<1, tl, mid, l, r), get(id<<1 | 1, mid+1, tr, l, r));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>s>>m;
	n=s.size();
	build(1, 1, n);
	while (m--){
		cin>>l>>r;
		cout<<get(1, 1, n, l, r).ans*2<<'\n';
	}
	
	return 0;
}