#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;
#define int long long

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
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        cin >> arr;
        int x, a, y, b;
        cin >> x >> a >> y >> b;
        sort(arr.rbegin(), arr.rend());
        int k;
        cin >> k;
        bool good = false;
        vector<int> pref(n + 1);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + arr[i - 1];
        }
        for (int i = 0; i < n; i++) {
            int cnta = (i + 1) / a;
            int cntb = (i + 1) / b;
            int cntab = (i + 1) / a / (b / __gcd(a, b));
            cnta -= cntab;
            cntb -= cntab;
            int anss = pref[cntab] / 100 * (x + y) + max((pref[cntab + cnta] - pref[cntab]) * x + (pref[cntab + cnta + cntb] - pref[cntab + cnta]) * y, (pref[cntab + cntb] - pref[cntab]) * y + (pref[cntab + cnta + cntb] - pref[cntab + cntb]) * x) / 100;
            if (anss >= k) {
                cout << i + 1 << endl;
                good = true;
                break;
            }
        }
        if (!good) {
            cout << -1 << endl;
        }
    }
}