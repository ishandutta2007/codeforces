#include<bits/stdc++.h>
#define ll long long
#define N 400015
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
int T, n, a[N];
string s[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> T;
	while(T--) {
		cin >> n;
		rep(i, 1, n) cin >> s[i];
		int ans = 0;
		rep(i, 0, 4) {
			rep(j, 1, n) a[j] = 0;
			rep(j, 1, n) for(auto x : s[j]) {
				if(x == 'a' + i) a[j]++;
				else a[j]--;
			}
			sort(a + 1, a + n + 1);
			reverse(a + 1, a + n + 1);
			int cnt = 0, sum = 0;
			rep(j, 1, n) {
				if(sum + a[j] > 0) sum += a[j], cnt++;
			}
			ans = max(ans, cnt);
		}
		cout << ans << endl;
	}
	return 0;
}