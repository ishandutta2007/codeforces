#include <bits/stdc++.h>
using namespace std;

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

int main() {
    int q;
    cin >> q;
    while (q--) {
        int h, n;
        cin >> h >> n;
        vector<int> arr(n);
        cin >> arr;
        int cur_ind = 0;
        int ans = 0;
        while (true) {
            if (cur_ind == n - 1) {
                break;
            }
            if (cur_ind == n - 2) {
                if (arr.back() != 1) {
                    ans++;
                }
                break;
            }
            if (arr[cur_ind + 2] == arr[cur_ind + 1] - 1) {
                cur_ind = cur_ind + 2;
                continue;
            }
            cur_ind++;
            ans++;
        }
        cout << ans << endl;
    }
}