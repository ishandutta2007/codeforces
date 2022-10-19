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
        int n;
        cin >> n;
        vector<int> arr(n);
        cin >> arr;
        map<int, int> m;
        for (int el : arr) {
            m[el] = 0;
        }
        int ind = 0;
        for (auto &el : m) {
            el.second = ind++;
        }
        vector<int> first(ind, -1), last(ind);
        for (int i = 0; i < n; i++) {
            if (first[m[arr[i]]] == -1) {
                first[m[arr[i]]] = i;
            }
            last[m[arr[i]]] = i;
        }
        vector<int> max_ans(ind, 1);
        for (int i = 1; i < ind; i++) {
            if (last[i - 1] < first[i]) {
                max_ans[i] = max_ans[i - 1] + 1;
            }
        }
        int max_anss = *max_element(max_ans.begin(), max_ans.end());
        cout << ind - max_anss << endl;
    }
}