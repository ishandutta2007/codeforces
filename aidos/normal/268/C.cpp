#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
int n, m, z;
cin >> n >> m;
z=min(n, m);
cout << z+1 << endl;
for(int i=z; i>=0; i--)
	cout << i << " " << z-i << endl;
return 0;
}