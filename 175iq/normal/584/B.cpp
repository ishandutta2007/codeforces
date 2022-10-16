#include <bits/stdc++.h>
using namespace std;



long long int mod(long long int a,long long int b, long long int c)
{
    if(b==0) return 1;
    
    if(b%2==0)
    {
        long long int x=mod(a,b/2,c);
        return (x*x)%c;
    }
    else 
    {
        long long int x=mod(a,b-1,c);
        return (a%c * x)%c;
    }
}



int main()
{
	long long int n;
	cin>>n;

    long long int MOD=pow(10,9)+7;
	long long int total=mod(27,n,MOD);
	//cout<<total<<endl;
	long long int sub=mod(7,n,MOD);
	//cout<<sub<<endl;

	long long int ans=(total%MOD-sub%MOD+MOD)%MOD;
	cout<<ans;
	return 0;
}