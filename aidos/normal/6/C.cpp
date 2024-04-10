#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
long long t1=0, t2=0;
int a[100010], n, i, j, k;
cin >> n;
for(i=0; i<n; i++) scanf("%d", &a[i]);
j=0, k=n-1;
while(j<k){
	while(t1>=t2+a[k] && j<k){
		t2+=a[k];
		k--;		
	}	
	while(t1+a[j]<=t2 && j<k){
		t1+=a[j];
		j++;		
	}
	if(j<k){
		t1+=a[j];
		t2+=a[k];
		j++;
		k--;
	}
}
if(j==k && t1<=t2){
	j++;	
}
cout << j << " "  << n-j; 
return 0;
}