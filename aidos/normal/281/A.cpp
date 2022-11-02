#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
int n, m;
string s;
cin >> s;
if(s[0]>='A' && s[0] <= 'Z') cout << s;
else {
	s[0] = s[0]-'a' + 'A';
	cout << s;
}
return 0;
}