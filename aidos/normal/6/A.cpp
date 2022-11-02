#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
int a[4], i;
for(i=0; i<4; i++)	cin >> a[i];
sort(a, a+4);
if(a[1]+a[0]>a[2] || a[3]<a[2]+a[1] || a[0]+a[1]>a[3]){
	cout << "TRIANGLE";	
}
else if(a[2]==a[0]+a[1] || a[3]==a[2]+a[1]||a[3]==a[0]+a[1])
	cout << "SEGMENT";
else cout << "IMPOSSIBLE";
return 0;
}