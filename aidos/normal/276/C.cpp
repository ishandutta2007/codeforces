#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
int n, a[250000], q[250000], l, r, x;
long long sum = 0;
cin >> n >> x;
for(int i=0; i<n; i++){
	scanf("%d", &a[i]);
	q[i] = 0;
}
sort(a, a+n);
q[n]=0;
for(int i=0; i<x; i++){
	scanf("%d%d", &l, &r);
	q[l-1]++;
	q[r]--;	
}
for(int i=1; i<n; i++)
	q[i] += q[i-1];
sort(q, q+n);
for(int i=0; i<n; i++){
	sum = sum+(q[i]*1ll*a[i]);	
}
cout << sum;
return 0;
}