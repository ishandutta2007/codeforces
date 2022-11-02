#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;               
long long d, x, ppow[100], z=0, f=0;
bool used[80];          
int main () {                       
int md, mx;
cin >> x >> d;
ppow[0] = 1;
for(int i=1; i<63; i++)
	ppow[i] = 2*ppow[i-1];
for(int i=0; i<70; i++)
	used[i] = 1;
for(int i=0; i<63; i++)
{
	if(x>=ppow[i]) mx=i;
	if(d>=ppow[i]) md = i;
}
if(x==d){
	cout << 0;
	return 0;
}
long long maxx =(d^x);
if(d-x<100){
	for(long long i=x; i<d; i++){
		for(long long j=i+1; j<=d; j++)
			if((j^i)>maxx){
				maxx = i^j;
			}
	}
	cout << maxx;
	return 0;
}
while(d && x){  
	if(md>mx) {
		cout << ppow[md+1]-1;
		return 0;
	}
	else {
	x-=ppow[mx];
	d-=ppow[md];
		mx = -1;
		md = -1;        
		for(int i=0; i<63; i++)
		{
			if(x>=ppow[i]) mx=i;
			if(d>=ppow[i]) md = i;
		}		
	}
}         
cout << 1;
return 0;
}