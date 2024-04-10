#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int gcd(int i, int j){
	if(i==0) return j;
	return gcd(j%i, i);
}
int main () {   
int n, m, k;
cin >> n >> m;
if(n>m) {
	m = 7-n;
}
else m=7-m;
k = gcd(m, 6);
cout << m/k << "/" << 6/k;
return 0;
}