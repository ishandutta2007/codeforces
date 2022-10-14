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
   	int cnt1 = 0, cnt2 = 0;
   	for (auto &c : a) {
   		cin >> c;
   		if (c == 1) {
   			cnt1++;
   		} else {
   			cnt2++;
   		}
   	}
   	if (cnt2 == 0) {
   		for (auto &c : a) {
   			cout << c << " ";
   		}
   		return 0;
   	}
   	if (cnt1 == 0) {
   		for (auto &c : a) {
   			cout << c << " ";
   		}
   		return 0;
   	}
   	cout << 2 << " ";
   	cnt2--;
   	if (cnt1 % 2 == 1) {
   		for (int i = 0; i < cnt1; i++) {
   			cout << 1 << " ";
   		}
   	} else {
   		for (int i = 0; i < cnt1 - 1; i++) {
   			cout << 1 << " ";
   		}
   	}
   	for (int i = 0; i < cnt2; i++) {
   		cout << 2 << " ";
   	}
   	if (cnt1 % 2 == 0) {
   		cout << 1;
   	}
    return 0;
}