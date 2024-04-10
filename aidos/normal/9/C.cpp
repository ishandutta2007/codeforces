#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int z, n, u[40], t;
int f(int k){
if(k==z){
	long m=0;
	for(int i=0; i<k; i++)
		m = 10*m + u[i];
	if(m <= n) return 1;
	return 0;					
}
u[k] = 0;
int l=f(k+1);
u[k] = 1;
l+=f(k+1);
return l;
}
int main () {
cin >> n;
t=n;
z=0;
while(t>0){
	z++;
	t/=10;
} 
cout << f(0)-1;
return 0;
}