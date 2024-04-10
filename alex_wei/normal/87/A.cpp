#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,d,l,r,x,y;
int main(){
	cin>>a>>b;
	d=a*b/__gcd(a,b);
	while(l*a!=r*b||l==0){
		if((l+1)*a<(r+1)*b||(l+1)*a==(r+1)*b&&a>b)x+=max(0ll,l*a+a-max(l*a,r*b)),l++;
		else y+=max(0ll,r*b+b-max(l*a,r*b)),r++;
	}
	if(x==y)puts("Equal");
	if(x>y)puts("Dasha");
	if(x<y)puts("Masha");
	return 0;
}
/////
/////
/////