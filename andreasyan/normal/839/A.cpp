#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;
const int N=102;

int a[N];
int n,m,k,k0;
int ans=-1;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		m+=a[i];
		if(m>=8)
		{
			m-=8;
			k0+=8;
		}
		else
		{
			k0+=m;
			m=0;
		}
		if(k0>=k)
		{
			ans=i;
			break;
		}
	}
	cout<<ans<<endl;
//	system("pause");
	return 0;
}