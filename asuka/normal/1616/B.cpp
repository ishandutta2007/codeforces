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
int T, n;
string s;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> T;
	while(T--) {
		cin >> n >> s;
		string ans1, ans2, ans3;
		rep(i, 0, n - 2) if(s[i] < s[i + 1]) {
			rep(j, 0, i) ans3 += s[j];
			per(j, 0, i) ans3 += s[j];
			break;
		}
		ans1 += s[0];
		ans1 += s[0];
		ans2 = s;
		reverse(all(s));
		ans2 += s;
		if(SZ(ans3) > 0) ans1 = min(ans1, ans3);
		cout << min({ans1, ans2}) << endl;
	}
	return 0;
}