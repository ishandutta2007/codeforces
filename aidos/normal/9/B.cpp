#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
int main () {   
int n, i, j, m=1; 
double vb, vs, x[110], xu, yu;
double t[110];
cin >> n >> vb >> vs;
for(i=0; i<n; i++){
	cin >> x[i];
	t[i] = 1.0*x[i]/vb;
}
cin >> xu >> yu;

for(i=1; i<n; i++){
	t[i] = t[i] + (sqrt((x[i]-xu)*(x[i]-xu)+yu*yu))/vs;
	if(t[i]<=t[m]) m=i;
}
cout << m+1;
return 0;
}