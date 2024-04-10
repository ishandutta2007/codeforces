#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;
typedef long double ldb;

template<typename T>
istream &operator>>(istream &in, vector<T> &arr) {
	for (auto &el : arr) {
		in >> el;
	}
	return in;
}


template<typename T, typename TT>
istream &operator>>(istream &in, pair<T, TT> &pp) {
	in >> pp.first >> pp.second;
	return in;
}

template<typename T>
ostream &operator<<(ostream &out, vector<T> &arr) {
	for (auto &el : arr) {
		out << el << " ";
	}
	return out;
}

template<typename T, typename TT>
ostream &operator<<(ostream &out, pair<T, TT> &pp) {
	out << pp.first << " " << pp.second;
	return out;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string arr = s;
        int l = 0;
        for (int r = 0; r < n; r++) {
            while (l < n - 1 && r - l > k) {
                l++;
            }
            while (l < n - 1 && arr[l] == '0') {
                l++;
            }
            if (arr[r] == '0' && l < r && r - l <= k) {
                swap(arr[l], arr[r]);
                k -= r - l;
            }
        }
        cout << arr << endl;
    }
	return 0;
}