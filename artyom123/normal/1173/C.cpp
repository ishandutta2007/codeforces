#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
   	int n;
   	cin >> n;
   	vector <int> a(n);
   	vector <int> b(n);
   	for (auto &c : a) {
   		cin >> c;
   	}
   	for (auto &c : b) {
   		cin >> c;
   	}
   	int ind = -1;
   	for (int i = 0; i < n; i++) {
   		if (b[i] == 1) {
   			ind = i;
   			break;
   		}
   	}
   	if (ind != -1) {
   		bool f = true;
   		for (int i = ind; i < n; i++) {
   			if (b[i] != i - ind + 1) {
   				f = false;
   				break;
   			}
   		}
   		if (f == true) {
   			queue <int> q;
   			for (int i = 0; i < n; i++) {
   				q.push(b[i]);
   			}
   			vector <int> cnt(n + 1);
   			for (auto &c : a) {
   				cnt[c]++;
   			}
   			int now = n - ind + 1;
   			while (now != n + 1) {
   				if (cnt[now] == 0) {
   					break;
   				}
   				cnt[q.front()]++;
   				cnt[now]--;
   				q.pop();
   				now++;
   			}
   			if (now == n + 1) {
   				cout << ind;
   				return 0;
   			}
   		}
   	}
   	vector <int> t(n + 1);
   	for (int i = 0; i < n; i++) {
   		t[b[i]] = i + 1;
   	}
   	int ma = -1;
   	for (int i = 1; i <= n; i++) {
   		ma = max(ma, t[i] - i + 1);
   	}
   	cout << n + max(0, ma);
    return 0;
}