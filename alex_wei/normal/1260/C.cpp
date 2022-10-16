#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,r,b,k;
int main()
{
	cin>>t;
	while(t--){
		cin>>r>>b>>k;
		int d=__gcd(r,b);
		r/=d,b/=d;
		if(r<b)swap(r,b);
		if(r==b)puts("OBEY");
		else{
			int c=(r-2)/b+1;
			if(c>=k)puts("REBEL");
			else puts("OBEY");
		}
	}
    return 0;
}