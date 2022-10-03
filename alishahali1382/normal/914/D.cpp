#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
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
const int MAXN = 500010, LOG=20;

int n, m, k, u, v, x, y, t, l, r, type, ans;
int A[MAXN];
int seg[4*MAXN];
vector<piii> node, bad;

int build(int id, int tl, int tr){
	if (tl==tr) return seg[id]=A[tl];
	int mid=(tl+tr)>>1;
	return seg[id]=__gcd(build(id<<1, tl, mid), build(id<<1 | 1, mid+1, tr));
}

int update(int id, int tl, int tr, int ind, int num){
	if (ind<tl || tr<ind) return seg[id];
	if (tl==tr) return seg[id]=num;
	int mid=(tl+tr)>>1;
	return seg[id]=__gcd(update(id<<1, tl, mid, ind, num), update(id<<1 | 1, mid+1, tr, ind, num));
}

void query(int id, int tl, int tr, int l, int r){
	if (tr<l || r<tl) return ;
	if (l<=tl && tr<=r){
		node.pb({id, {tl, tr}});
		return ;
	}
	int mid=(tl+tr)>>1;
	query(id<<1, tl, mid, l, r);
	query(id<<1 | 1, mid+1, tr, l, r);
}

bool ok(int id, int tl, int tr, int x){
	if (tl==tr) return 1;
	int mid=(tl+tr)>>1;
	if (seg[id<<1]%x){
		if (seg[id<<1 | 1]%x) return 0;
		return ok(id<<1, tl, mid, x);
	}
	return ok(id<<1 | 1, mid+1, tr, x);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	build(1, 1, n);
	cin>>m;
	while (m--){
		cin>>type;
		if (type==2){
			cin>>x>>y;
			update(1, 1, n, x, y);
			continue ;
		}
		node.clear();
		bad.clear();
		cin>>l>>r>>x;
		query(1, 1, n, l, r);
		for (auto p:node) if (seg[p.first]%x) bad.pb(p);
		if (bad.size()>1){
			cout<<"NO\n";
			continue ;
		}
		if (bad.size()==0 || ok(bad[0].first, bad[0].second.first, bad[0].second.second, x)){
			cout<<"YES\n";
			continue ;
		}
		cout<<"NO\n";
	}
	
	
	return 0;
}
/*
4
3 3 7 7
1
1 1 4 3

*/
/*
      ___           ___                            ___           ___           ___           ___           ___           ___
     /\  \         /\__\      ___                 /\  \         /\__\         /\  \         /\__\         /\  \         /\__\      ___
    /::\  \       /:/  /     /\  \               /::\  \       /:/  /        /::\  \       /:/  /        /::\  \       /:/  /     /\  \
   /:/\:\  \     /:/  /      \:\  \             /:/\ \  \     /:/__/        /:/\:\  \     /:/__/        /:/\:\  \     /:/  /      \:\  \
  /::\~\:\  \   /:/  /       /::\__\           _\:\~\ \  \   /::\  \ ___   /::\~\:\  \   /::\  \ ___   /::\~\:\  \   /:/  /       /::\__\
 /:/\:\ \:\__\ /:/__/     __/:/\/__/          /\ \:\ \ \__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/__/     __/:/\/__/
 \/__\:\/:/  / \:\  \    /\/:/  /             \:\ \:\ \/__/ \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \:\  \    /\/:/  /
      \::/  /   \:\  \   \::/__/               \:\ \:\__\        \::/  /       \::/  /       \::/  /       \::/  /   \:\  \   \::/__/
      /:/  /     \:\  \   \:\__\                \:\/:/  /        /:/  /        /:/  /        /:/  /        /:/  /     \:\  \   \:\__\
     /:/  /       \:\__\   \/__/                 \::/  /        /:/  /        /:/  /        /:/  /        /:/  /       \:\__\   \/__/
     \/__/         \/__/                          \/__/         \/__/         \/__/         \/__/         \/__/         \/__/
*/