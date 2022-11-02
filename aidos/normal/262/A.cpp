#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int f(int t){
int z=0;
while(t>0){
int l=t%10;
if(l==4 || l==7) z++;
t/=10;
}
return z;
}
int main () {   
int n, k, l=0, t, m;
cin >> n >> k;
for(int i=0; i<n; i++){
	cin >> t;
	m = f(t);
	if(m<=k) l++;
}
cout << l;
return 0;
}