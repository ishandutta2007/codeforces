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
string a, b;
cin >> a >> b;
int as = a.size(), bs = b.size(), k=0, l=0;
if(a==b) cout << "YES";
else if(as!=bs) cout << "NO";
else {
	for(int i=0; i<as; i++)
		k+= a[i]-'0';

	for(int i=0; i<bs; i++)
		l+= b[i]-'0';
    if(l==0 || k==0) cout << "NO";
   	else cout << "YES";
}
return 0;
}