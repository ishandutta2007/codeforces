#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int a[k];
	for(int i=0;i<k;i++) scanf("%d",&a[i]);
	vector<int> first(n+1,1000000000);
	vector<int> last(n+1,-1);
	for(int i=0;i<k;i++)
    {
        first[a[i]]=min(first[a[i]],i);
        last[a[i]]=max(last[a[i]],i);
    }
    int res=0;
    for(int o=1;o<=n;o++)
    {
        for(int i=o-1;i<=o+1;i++)
        {
            if(i==0||i==n+1) continue;
            if(first[o]>last[i]) res++;
        }
    }
    printf("%d\n",res);
	return 0;
}