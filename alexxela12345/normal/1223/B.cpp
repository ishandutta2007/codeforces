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
        string s, t;
        cin >> s >> t;
        set<char> s1, s2;
        for (auto el : s) {
            s1.insert(el);
        }
        for (auto el : t) {
            s2.insert(el);
        }
        bool good = false;
        for (auto el : s1) {
            if (s2.count(el)) {
                good = true;
            }
        }
        if (good) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }
}