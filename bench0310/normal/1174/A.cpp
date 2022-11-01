#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	n*=2;
	vector<int> v(n);
	for(int i=0;i<n;i++) scanf("%d",&v[i]);
	sort(v.begin(),v.end());
	if(v[0]!=v[n-1]) for(int i=0;i<n;i++) printf("%d ",v[i]);
	else printf("-1");
	printf("\n");
	return 0;
}