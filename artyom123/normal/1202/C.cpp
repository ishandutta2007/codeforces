#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int INF = 1e9 + 1;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
   	int t;
   	cin >> t;
   	while (t--) {
   		string s;
   		cin >> s;
   		vector <int> a, b;
   		for (auto &l : s) {
   			if (l == 'W') {
   				b.pb(1);
   			}
   			if (l == 'A') {
   				a.pb(-1);
   			}
   			if (l == 'D') {
   				a.pb(1);
   			}
   			if (l == 'S') {
   				b.pb(-1);
   			}
   		}
   		long long max_bal_a = 0, min_bal_a = 0, max_bal_b = 0, min_bal_b = 0;
   		long long now = 0;
   		for (auto &c : a) {
   			now += c;
   			max_bal_a = max(max_bal_a, now);
   			min_bal_a = min(min_bal_a, now);
   		}
   		now = 0;
   		for (auto &c : b) {
   			now += c;
   			max_bal_b = max(max_bal_b, now);
   			min_bal_b = min(min_bal_b, now);
   		}
   		long long ans = (max_bal_a - min_bal_a + 1) * (max_bal_b - min_bal_b + 1);
   		now = 0;
   		bool f = false;
   		long long MAXA = max_bal_a;
   		long long MINA = min_bal_a;
   		long long MAXB = max_bal_b;
   		long long MINB = min_bal_b;
   		max_bal_a = 0;
   		min_bal_a = 0;
   		for (int i = 0; i < a.size(); i++) {
   			if (now + a[i] == MAXA && f == false) {
   				f = true;
   				now--;
   				max_bal_a = max(max_bal_a, now);
   				min_bal_a = min(min_bal_a, now);
   			}
   			now += a[i];
   			max_bal_a = max(max_bal_a, now);
   			min_bal_a = min(min_bal_a, now);
   		}
   		ans = min(ans, (max_bal_a - min_bal_a + 1) * (MAXB - MINB + 1));
   		max_bal_a = 0;
   		min_bal_a = 0;
   		f = false;
   		now = 0;
   		for (int i = 0; i < a.size(); i++) {
   			if (now + a[i] == MINA && f == false) {
   				f = true;
   				now++;
   				max_bal_a = max(max_bal_a, now);
   				min_bal_a = min(min_bal_a, now);
   			}
   			now += a[i];
   			max_bal_a = max(max_bal_a, now);
   			min_bal_a = min(min_bal_a, now);
   		}
   		ans = min(ans, (max_bal_a - min_bal_a + 1) * (MAXB - MINB + 1));
   		max_bal_b = 0;
   		min_bal_b = 0;
   		f = false;
   		now = 0;
   		for (int i = 0; i < b.size(); i++) {
   			if (now + b[i] == MAXB && f == false) {
   				f = true;
   				now--;
   				max_bal_b = max(max_bal_b, now);
   				min_bal_b = min(min_bal_b, now);
   			}
   			now += b[i];
   			max_bal_b = max(max_bal_b, now);
   			min_bal_b = min(min_bal_b, now);
   		}
   		ans = min(ans, (MAXA - MINA + 1) * (max_bal_b - min_bal_b + 1));
   		max_bal_b = 0;
   		min_bal_b = 0;
   		f = false;
   		now = 0;
   		for (int i = 0; i < b.size(); i++) {
   			if (now + b[i] == MINB && f == false) {
   				f = true;
   				now++;
   				max_bal_b = max(max_bal_b, now);
   				min_bal_b = min(min_bal_b, now);
   			}
   			now += b[i];
   			max_bal_b = max(max_bal_b, now);
   			min_bal_b = min(min_bal_b, now);
   		}
   		ans = min(ans, (MAXA - MINA + 1) * (max_bal_b - min_bal_b + 1));
   		cout << ans << "\n";
   	}
    return 0;
}