#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
int  d, su, mi[40], ma[40], k=0, z=0, c[40];
cin >> d >> su;
for(int i=0; i<d; i++){
	cin >> mi[i] >> ma[i];
	k+=mi[i];
	z+=ma[i];
}
if(su<k || su>z){
	cout << "NO";
}
else {
	cout << "YES\n";
	int t=0;
	su-=k;             
	while(su>0){
		int z=min(su,ma[t]-mi[t]);
		mi[t]+=z;
		su-=z;
		t++;				
	}
	for(int i=0; i<d; i++) cout << mi[i] << " ";
}
return 0;
}