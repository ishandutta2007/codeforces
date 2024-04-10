#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
int n, a[110], d, b[110][110];
cin >> n;
cin >> a[0];
d=a[0];
b[0][0] = a[0];
for(int i=1; i<n; i++){
	cin >> a[i];              
	for(int j=0; j<i; j++)
			b[i][j] = a[i]^b[i-1][j];
	b[i][i] = a[i];
	for(int j=0; j<=i; j++)
		if(b[i][j]>d) d=b[i][j];
}   
cout << d;
return 0;
}