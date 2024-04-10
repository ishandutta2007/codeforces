#include <iostream>
#include <deque>
using namespace std;
int a[200005];
bool ex[200005];
int main()
{
	int n,mx=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		ex[a[i]]=1;
	}
	deque<int> d;
	for (int i=0;i<n;i++)
	{
		int b;
		scanf("%d",&b);
		d.push_back(b);
		if (b)
		mx=max(mx,i-b+2);
	}
	bool ok=0;
	for (int i=0;i<d.size();i++)
	{
		if (d[i]==1)
		{
			ok=1;
			for (int j=i+1;j<d.size();j++)
			ok&=(d[j]==j-i+1);
			break;
		}
	}
	int tmp=0;
	if (!ok)
	{
		tmp=1e9;
		goto out;
	}
	while (d.back()!=n)
	{
		if (ex[d.back()+1])
		{
			d.push_back(d.back()+1);
			ex[d.back()]=0;
			ex[d.front()]=1;
			d.pop_front();
		}
		else
		{
			tmp=1e9;
			break;
		}
		tmp++;
	}
	out:
	printf("%d",min(mx+n,tmp));
}