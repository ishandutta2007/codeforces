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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        cin >> arr;
        multiset<int> s;
        for (int el : arr) {
            s.insert(el);
        }
        if (s.count(2048) >= 1) {
            cout << "YES" << endl;
            continue;
        }
        bool good = false;
        while (s.size() >= 2) {
            int a = *s.begin();
            s.erase(s.begin());
            int b = *s.begin();
            s.erase(s.begin());
            if (a == b) {
                if (a + b == 2048) {
                    cout << "YES" << endl;
                    good = true;
                    break;
                }
                if (a <= 512)
                    s.insert(a + b);
            } else {
                s.insert(b);
            }
        }
        if (!good) {
            cout << "NO" << endl;
        }
    }
}