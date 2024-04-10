#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=2*100005;

int n;
int a[N];
long long m;
int main()
{
	int i,j;
	cin>>n;
	for(i=0;i<n;++i)
	{
		scanf("%d",&j);
		a[j]=i;
	}
	for(i=2;i<=n;++i)
	{
		m+=abs(a[i]-a[i-1]);
	}
	cout<<m<<endl;
	return 0;
}