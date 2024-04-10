#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
int n, k=0, l, z=0;
cin >> n;
for(int i=0; i<n; i++){
	cin >> l;
	k=k+l;		
}
for(int i=1; i<6; i++){
	if(((k+i)%(n+1))!=1) {
		z++;      	
	}
}
cout << z;
return 0;
}