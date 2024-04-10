#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>

const int N=100005;	

int n,a[N];
std::multiset<int> se;
std::multiset<int>::iterator it;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),se.insert(a[i]);
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		it=se.upper_bound(a[i]);
		if (it==se.end()) continue;
		ans++;
		se.erase(it);
	}
	printf("%d",ans);
	return 0;
}