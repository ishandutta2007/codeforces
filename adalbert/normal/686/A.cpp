#include <iostream>
using namespace std;
long long n,x,h,ans;
char c;
int main() 
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		cin>>h;
		if (c=='+') x+=h; else
		if (c=='-')
		{
			if (x>=h) x-=h; else
			ans++;
		}
	}
cout<<x<<' '<<ans;
}