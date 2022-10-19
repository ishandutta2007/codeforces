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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> c(m);
    cin >> c;
    vector<int> arr;
    int cur = -1;
    int ii = 0;
    for (int el : c) {
        ii++;
        for (int i = 0; i < d - 1 && arr.size() < n; i++) {
            arr.push_back(0);
        }
        for (int i = cur + d; i < cur + d + el; i++) {
            arr.push_back(ii);
        }
        cur = cur + d + el - 1;
    }
    for (int i = 0; i < d - 1; i++) {
        arr.push_back(0);
    }
    while (arr.size() > n) {
        arr.erase(find(arr.begin(), arr.end(), 0));
    }
    if (arr.size() >= n) {
        cout << "YES" << endl;
        cout << arr << endl;
    } else {
        cout << "NO" << endl;
    }
	return 0;
}