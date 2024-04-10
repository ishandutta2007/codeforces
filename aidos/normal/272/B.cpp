#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
long long f(int n){
if(n==0) return 0;
if(n%2==0){
	return f(n/2);
}
else return f(n/2)+1;
}
int main () {   
int n, k;
long long l=0;
cin >> n;
map <long long, int> m;
for(int i=0; i<n; i++){
	scanf("%d", &k);
	m[f(k)]++;			
}                    
for(map<long long, int >::iterator it=m.begin(); it!=m.end(); it++){
	int g = (*it).second;
	if(g!=1) l+=((g*1ll*(g-1))/2);
}
cout << l;
return 0;
}