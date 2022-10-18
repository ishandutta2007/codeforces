#include <iostream>
#define __ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

const long long MOD=1e9+7;
long long pow(long long a,long long n)
{
	long long re=1;
	for(;n;n/=2,a=a*a%MOD)
		if(n&1) re=re*a%MOD;
	return re;
}

int main()
{
	long long test,m,k;
	cin >> test >> m >> k;
	if(((test+m)&1) && k==-1) puts("0"); 
	else cout << pow(pow(2,test-1),m-1) << "\n"; 
}