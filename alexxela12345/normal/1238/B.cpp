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
        int n, r;
        cin >> n >> r;
        vector<int> arr(n);
        cin >> arr;
        sort(arr.begin(), arr.end());
        int ind_r = n - 1;
        int ind_l = 0;
        int cnt = 0;
        while (ind_l <= ind_r) {
            int xx = ind_r;
            while (ind_r >= 0 && arr[ind_r] == arr[xx]) {
                ind_r--;
            }
            cnt++;
            while (arr[ind_l] - cnt * r <= 0) {
                ind_l++;
            }
        }
        cout << cnt << endl;
    }
}