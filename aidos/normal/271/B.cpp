#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>
#include <cstring>
#include <string>
using namespace std;   
vector <bool> is_p(130010, 0);
vector <int> v(130000, 0);
int main () {
int d[510][510], n, m, k, t, l=10000009;
is_p[1] = 1;
for(int i=2; i<320; i++){
	if(!is_p[i]){
		for(int j=2; i*j<130004; j++){
			is_p[i*j] = 1;
		}
	}	
}
t = 100003;
for(int i=100001; i>0; i--){
	if(!is_p[i]) {
		v[i] = i;
		t = i;  
	}
	else v[i] = t;
}
cin >> n >> m;
for(int i=0; i<n; i++){
	int z=0;
	for(int j=0; j<m; j++){
		scanf("%d", &k);
		d[i][j] = v[k] - k;
		z+=d[i][j];
	}
	if(z<l) l =z;
}
for(int i=0; i<m; i++){
	int z=0;
	for(int j=0; j<n; j++){
		z+=d[j][i];						          	
	}	    	
	if(l>z) l = z;
}

cout << l;
return 0;
}