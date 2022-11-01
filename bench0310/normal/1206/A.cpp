#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> a(n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	int m;
	scanf("%d",&m);
	vector<int> b(m);
	for(int i=0;i<m;i++) scanf("%d",&b[i]);
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	printf("%d %d\n",a.back(),b.back());
	return 0;
}