#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int x;

    cin >> s;
    cin >> x;

    if (s == "ABC") {
        puts(x < 2000 ? "YES" : "NO");
    } else if (s == "ARC") {
        puts(x < 2800 ? "YES" : "NO");
    } else {
        puts(x >= 1200 ? "YES" : "NO");
    }
	return 0;
}