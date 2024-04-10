#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
int main () {
int n, t;
cin >> n >> t;
string s;
cin >> s;
for(int j=0; j<t; j++)
	for(int i=1; i<n; i++)
		if(s[i]=='G' && s[i-1]=='B') {
			swap(s[i], s[i-1]);
			i++;	
		}
cout << s;
return 0;
}