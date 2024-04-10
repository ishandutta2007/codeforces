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
int T;
string s, t;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> T;
	while(T--) {
		cin >> n >> s >> t;
		int dif[2] = {0, 0}, sam[2] = {0, 0};
		rep(i, 0, n - 1) {
			if(s[i] == t[i]) sam[s[i] - '0']++;
			else dif[s[i] - '0']++;
		}
		int ans = inf;
		if((dif[0] + dif[1]) % 2 == 0 && dif[1] >= dif[0] && dif[0] + 1 >= dif[1]) ans = min(ans, dif[0] + dif[1]);
		if((sam[0] + sam[1]) % 2 == 1 && sam[1] >= sam[0] && sam[0] + 1 >= sam[1]) ans = min(ans, sam[0] + sam[1]);
		printf("%d\n", ans == inf ? -1 : ans);
	}
	return 0;
}