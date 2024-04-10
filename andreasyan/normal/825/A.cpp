#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int n;
string ans,a;
int main()
{
	int i,j,k=0;
	cin>>n;
	cin>>a;
	for(i=0;i<n;++i)
	{
		if(a[i]=='1')
		{
			++k;
		}
		else
		{
			ans+=(k+'0');
			k=0;
		}
	}
	ans+=(k+'0');
	cout<<ans<<endl;
	return 0;
}