#include<cstdio>
#include<queue>
using namespace std;
deque<int> a;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)a.push_back(i);
	for(int i=2;i<=n;i++)
	{
		int pos=(n-1)/i*i;a.push_back(a[pos]);
		while(pos-i>=0)a[pos]=a[pos-i],pos-=i;
		a.pop_front();
	}
	for(int i=0;i<n;i++)printf("%d ",a[i]);
	return 0;
}