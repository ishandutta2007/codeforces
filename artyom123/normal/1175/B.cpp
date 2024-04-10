#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int INF = 1e9 + 1;
const long long need = (1LL << 32) - 1;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
   	int l;
   	cin >> l;
   	stack <pair<int, long long>> st;
   	bool f = false;
   	long long ans = 0;
   	for (int i = 0; i < l; i++) {
   		string now;
   		cin >> now;
   		if (now == "for") {
   			int n;
   			cin >> n;
   			st.push({n, 0});
   		}
   		if (now == "add") {
   			if (st.empty()) {
   				ans++;
   				if (ans > need) {
   					f = true;
   				}
   				continue;
   			} else {
   				st.top().second += st.top().first;
   				if (st.top().second > need) {
   					f = true;
   				}
   			}
   		}
   		if (now == "end") {
   			long long k = st.top().second;
   			st.pop();
   			if (st.empty()) {
   				ans += k;
   				if (ans > need) {
   					f = true;
   				}
   			} else {
   				st.top().second += k * st.top().first;
   				if (st.top().second > need) {
   					f = true;
   				}
   			}
   		}
   	}
   	if (f == true) {
   		cout << "OVERFLOW!!!";
   		return 0;
   	}
   	cout << ans;
    return 0;
}