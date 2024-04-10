#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n/2;i++)
	{
		a.push_back(i+1);
		a.push_back(n-i);
	}
	if (n%2)
	a.push_back(n/2+1);
	for (int i=a.size()-1;i>=0;i--)
	a.push_back(a[i]);
	while (a.size()<=n*m)
	{
		int tmp=a.size();
		for (int i=0;i<tmp;i++)
		a.push_back(a[i]);
	}
	for (int i=0;i<n*m;i++)
	{
		int tmp=i/(2*n);
		printf("%d ",a[i]);
		if (m%2 && i>=(m-1)*n)
		printf("%d\n",m/2+1);
		else if (i%2)
		printf("%d\n",m-tmp);
		else
		printf("%d\n",tmp+1);
	}
}