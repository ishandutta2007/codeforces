#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <string>
#define pb push_back
#define mp make_pair
using namespace std;
double  a[200100], z[200100],l=0;
int t;
int m = 1, u;
int main () {
int n, x;                               
a[0] = 0;
z[0] = 0;
cin >> n;
for(int i=0; i<=n; i++)
	z[i] = 0;
for(int i=0; i<n; i++){
	scanf("%d", &t);
	if(t==1) {
	    scanf("%d%d", &x, &u);
		l += x*u;
		z[x-1]+=u;  	
	}
	else if(t==2){
	    scanf("%lf", &a[m]);
		l+=a[m];
		z[m] = 0;
		m++;
	}
	else if(t==3){
		
		m--;
		l-=(a[m]+z[m]);
			
		z[m-1]+=z[m];
			
	}                       	
	printf("%0.10lf\n", l/m);
}                           

return 0;
}