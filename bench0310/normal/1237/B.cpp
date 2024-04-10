#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int a[n],b[n];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) scanf("%d",&b[i]);
	int res=0;
	vector<bool> v(n+1,0);
	int idx=0;
	for(int i=0;i<n;i++)
    {
        if(v[a[i]]==1) continue;
        while(idx<n&&b[idx]!=a[i])
        {
            res++;
            v[b[idx]]=1;
            idx++;
        }
        idx++;
    }
    printf("%d\n",res);
	return 0;
}