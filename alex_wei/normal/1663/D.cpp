#include <bits/stdc++.h>
using namespace std;
string s;
int x;
int main() {
	cin >> s >> x;
	if(s == "ABC" && x < 2000) puts("Yes");
	else if(s == "ARC" && x < 2800) puts("Yes");
	else if(s == "AGC" && x >= 1200) puts("Yes");
	else puts("No");
    return 0;
}