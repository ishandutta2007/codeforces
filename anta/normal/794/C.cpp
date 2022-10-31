#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

string naiverec(string A, string B, int k, string &ans) {
	if (k == ans.size())
		return ans;
	string &X = k % 2 == 0 ? A : B;
	string r = k % 2 == 0 ? "~" : "";
	rep(j, X.size()) {
		swap(X[j], X.back());
		rep(i, ans.size()) if (ans[i] == '?') {
			char c = X.back();
			X.pop_back();
			ans[i] = c;
			string t = naiverec(A, B, k + 1, ans);
			ans[i] = '?';
			X.push_back(c);
			if (k % 2 == 0)
				amin(r, t);
			else
				amax(r, t);
		}
		swap(X[j], X.back());
	}
	return r;
}

int main() {
	char buf[300001];
	while (~scanf("%s", buf)) {
		string A = buf;
		scanf("%s", buf);
		string B = buf;
		int n = (int)A.size();
		sort(A.rbegin(), A.rend());
		sort(B.begin(), B.end());

		string ans;
		{
			string tA = A, tB = B;
			rep(k, n) {
				if (tA.back() >= tB.back())
					break;
				string &X = k % 2 == 0 ? tA : tB;
				ans += X.back();
				X.pop_back();
			}
			int num[2] = {};
			reu(k, ans.size(), n)
				++num[k%2];
			reverse(tA.end() - num[0], tA.end());
			reverse(tB.end() - num[1], tB.end());
			string ans2;
			reu(k, ans.size(), n) {
				string &X = k % 2 == 0 ? tA : tB;
				ans2 += X.back();
				X.pop_back();
			}
			reverse(ans2.begin(), ans2.end());
			ans += ans2;
		}
		puts(ans.c_str());
	}
	return 0;
}