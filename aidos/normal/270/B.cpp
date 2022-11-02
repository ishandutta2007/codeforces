#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
int i, n, a[100010];
cin >> n;
for(i=0; i<n; i++){
	scanf("%ld", &a[i]);
}   
for(i=n-1; i>0; i--){
	if(a[i]<a[i-1]){
		cout << i;
		return 0;
	}
}
cout << 0;
return 0;
}