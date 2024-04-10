
// Problem : E. Rescue Niwen!
// Contest : Codeforces - Codeforces Round #741 (Div. 2)
// URL : https://codeforces.com/contest/1562/problem/E
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N;

struct SuffixArray {
	vector<int> a;
	string s;
	SuffixArray(const string& _s) : s(_s + '\0') {
		int N = s.size();
		vector<pair<int, int>> b(N);
		a.resize(N);
		for(int i = 0; i < N; i++) {
			b[i].first = s[i];
			b[i].second = i;
		}

		int q = 8;
		while ((1 << q) < N) q++;
		for (int moc = 0;; moc++) {
			sort(b.begin(), b.end()); // sort(all(b)) can be used as well
			a[b[0].second] = 0;
			for(int i = 1; i < N; i++){
				a[b[i].second] = a[b[i - 1].second] + (b[i - 1].first != b[i].first);
			}

			if ((1 << moc) >= N) break;
			for(int i = 0; i < N; i++) {
				b[i].first = a[i] << q;
				if (i + (1 << moc) < N)
					b[i].first += a[i + (1 << moc)];
				b[i].second = i;
			}
		}
		for(int i = 0; i < a.size(); i++) a[i] = b[i].second;
	}
	vector<int> lcp() {
		// longest common prefixes: res[i] = lcp(a[i], a[i-1])
		int n = a.size(), h = 0;
		vector<int> inv(n), res(n);
		for(int i = 0; i < n; i++) inv[a[i]] = i;
		for(int i = 0; i < n; i++) if (inv[i] > 0) {
			int p0 = a[inv[i] - 1];
			while (s[i + h] == s[p0 + h]) h++;
			res[inv[i]] = h;
			if(h > 0) h--;
		}
		return res;
	}
};

int dp[5005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		string s;
		cin >> s;
		SuffixArray sa = SuffixArray(s);
		auto lcparray = sa.lcp();
		for(int i = 1; i <= N; i++){
			dp[i] = N - sa.a[i];
			int k = INT_MAX;
			for(int j = i-1; j; j--){
				k = min(k, lcparray[j+1]);
				if(sa.a[j] < sa.a[i]){
					dp[i] = max(dp[i], dp[j] + N - sa.a[i] - k);
				}
			}
		}		
		cout << *(max_element(dp+1, dp+1+N)) << "\n";
	}
}