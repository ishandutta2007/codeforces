#include <bits/stdc++.h> 

using namespace std;

int n;
string a, b, c, d;

int main (int argc, char const *argv[]) {
	cin >> a >> b >> n;
	while (n--) {
		cout << a << " " << b << '\n';
		cin >> c >> d;
		if (c == a) a = d;
		else b = d;
	}
	cout << a << " " << b << '\n';
    return 0;
}