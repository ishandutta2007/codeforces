#include<bits/stdc++.h>
#define ll long long
#define N 200015
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
int n, cnt[N], sum[N], ans, al, ar;
deque<int> res;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	int Max = 0;
	rep(i, 1, n) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
		Max = max(Max, x);
	}
	rep(i, 1, Max) sum[i] = cnt[i] + sum[i - 1];
	int l = 1;
	rep(r, 1, Max) {
		if(cnt[r] == 0) l = r + 1;
		if(l <= r && sum[r] - sum[l - 1] > ans) {
			ans = sum[r] - sum[l - 1];
			al = l;
			ar = r;
		}
		if(cnt[r] == 1) l = r; 
	}
	rep(i, al, ar) {
		res.pb(i);
		rep(_, 1, cnt[i] - 1) res.push_front(i);
	}
	printf("%d\n", SZ(res));
	for(auto x : res) printf("%d ", x);
	return 0;
}