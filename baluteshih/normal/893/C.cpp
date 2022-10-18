#include <iostream>
#define __ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

long long unions[100050],arr[100050];

long long f(long long n)
{
	if(unions[n]==n) return n;
	return unions[n]=f(unions[n]);
}

int main()
{
	long long n,m,a,b;
	cin >> n >> m; 
	for(a=1;a<=n;a++)
		cin >> arr[a],unions[a]=a;
	while(m--)
	{
		cin >> a >> b;
		unions[f(a)]=f(b);
	}
	for(a=1;a<=n;a++)
	{
		if(f(a)!=a)
		{
			arr[unions[a]]=min(arr[unions[a]],arr[a]);
			arr[a]=0;
		}
	}
	for(a=1,b=0;a<=n;a++)
		b+=arr[a];
	cout << b << "\n";
}