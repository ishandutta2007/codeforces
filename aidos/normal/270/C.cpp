#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
int n;
long k, z, t=0, m[33];
pair <long, long> p[100010];
cin >> n;
for(int i=0; i<n; i++){
	scanf("%ld%ld", &k, &z);
	long  long l=1;
	int c=0;
	while(z>l||l==1){
		l*=4;
		c++;		
	}
	t = max(t, c+k);
}                   
cout << t;
return 0;
}