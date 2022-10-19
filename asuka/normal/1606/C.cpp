#include<bits/stdc++.h>
#define ll long long
#define N
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
int t, n, k, a[15];
int pd[15];
string ans;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	pd[0] = 1;
	rep(i, 1, 9) pd[i] = pd[i - 1] * 10;
	while(t--) {
		scanf("%d%d", &n, &k);
		k++;
		ans.clear();
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) {
			if(k == 0) break;
			int val = min(k, i < n ? (pd[a[i + 1] - a[i]] - 1) : (k));
			string x = to_string(val);
			reverse(all(x));
			ans += x;
			k -= val;
		}
		reverse(all(ans));
		for(auto x : ans) putchar(x);
		printf("\n");
	}
	return 0;
}