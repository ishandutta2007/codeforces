#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
int n, k, l=0, a[110], h[110];  
cin >> n;
for(int i=0; i<n; i++)
	cin >> a[i] >> h[i];
for(int i=0; i<n; i++)
	for(int j=0; j<n; j++){
		if(a[i]==h[j]) l++;
	}
cout << l;	
return 0;
}