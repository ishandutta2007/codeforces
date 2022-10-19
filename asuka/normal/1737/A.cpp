#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		vector<int> buc(26, 0);
		rep(i, 0, n - 1) buc[s[i] - 'a']++;

		rep(i, 1, k) {
			char ch = 'a';

			rep(j, 0, n / k - 1) {
				if (buc[j] > 0) {
					buc[j]--;
					ch = 'a' + j + 1;
				} else break;
			}

			cout << ch;
		}

		cout << '\n';
	}
	return 0;
}