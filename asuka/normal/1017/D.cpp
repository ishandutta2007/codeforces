#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n, m, q, cnt[1 << 12], w[14], val[1 << 12];
int pre[1 << 12][105];
string o;
int to_int(string s) {
	int res = 0;
	for(auto c : s) res = res * 2 + (c - '0');
	return res;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> q;
	rep(i, 0, n - 1) cin >> w[i];
	rep(i, 1, m) {
		cin >> o;
		reverse(all(o));
		cnt[to_int(o)]++;
	}
	rep(mask, 0, (1 << n) - 1) {
		rep(k, 0, n - 1) if(mask >> k & 1) val[mask] += w[k];
	}
	rep(i, 0, (1 << n) - 1) {
		rep(j, 0, (1 << n) - 1) {
			int mask = ~(i ^ j) & ((1 << n) - 1);
			if(val[mask] <= 100) pre[i][val[mask]] += cnt[j];
		}
		rep(j, 1, 100) pre[i][j] += pre[i][j - 1];
	}
	rep(i, 1, q) {
		int k;
		cin >> o >> k;
		reverse(all(o));
		cout << pre[to_int(o)][k] << endl;
	}
	return 0;
}