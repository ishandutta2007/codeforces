#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
vector <int> v;
long long sn=0, sp=0;
int n, mx=10001, l, k;
cin >> n >> k;
for(int i=0; i<n;i++){
	cin >> l;            
	if(l<0){
		v.push_back(l);
		int z= abs(l);
		if(z < mx) mx = z ;
	}
	else {
		sp+=l;
		if(l<mx) mx = l;
	}
}
sort(v.begin(), v.end());
int s=v.size();
if(k>s){
	for(int i=0; i<s; i++)
		sp += -v[i];
	k-=s;
	if(k%2==1) sp -= (2*mx);
}   
else {                                     
	for(int i=0; i<k; i++)
		sp+= -v[i];
   	for(int i=k; i<s; i++)
   		sp += v[i];
} 
cout << sp;
return 0;
}