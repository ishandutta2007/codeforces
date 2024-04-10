#include <bits/stdc++.h>

#define ll long long

using namespace std;

string to_str(int p) {
    if (p == 0) {
        return "0";
    }
	string s = "";
	bool sign = (p < 0);
	p = abs(p);
	while (p > 0) {
		s += ((p % 10) + '0');
		p /= 10;
	}
	if (sign) {
		s += "-";
	}
	reverse(s.begin(), s.end());
	return s;
}

int main() {
	srand(time(NULL));
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	int n;
	cin >> n;
	multiset <int> cur;
	int x;
	int mn = -1000000000;
	vector <string> a;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "insert") {
			cin >> x;
			cur.insert(x);
			a.push_back("insert " + to_str(x));
		} else if (s == "getMin") {
			cin >> x;
			while (cur.size() && x > *cur.begin()) {
				a.push_back("removeMin");
				cur.erase(cur.begin());
			}
            if (cur.size() == 0 || x < *cur.begin()) {
            	a.push_back("insert " + to_str(x));
            	cur.insert(x);
            } 
            a.push_back("getMin " + to_str(x));
		} else {
			if (cur.size() == 0) {
				a.push_back("insert " + to_str(mn));
				cur.insert(mn);
			}
			a.push_back("removeMin");
			cur.erase(cur.begin());
		}
	}
	cout << a.size() << '\n';
	for (int i = 0; i < (int) a.size(); i++) {
		cout << a[i] << '\n';
	}
}