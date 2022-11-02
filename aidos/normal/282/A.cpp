#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <string>
#define pb push_back
#define mp make_pair
using namespace std;
int main () {
int n, x=0;
string s;
cin >> n;
for(int i=0; i<n; i++){
	cin >> s;
	if(s[0]=='+' || s[2]=='+') x++;
	else x--;
}
cout << x;
return 0;
}