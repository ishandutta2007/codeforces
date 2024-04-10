#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int> t(n);
	for(int i=0;i<n;i++) scanf("%d",&t[i]);
	vector<int> v(101,0);
	int sum=0;
	for(int o=0;o<n;o++)
    {
        int now=sum+t[o]-m;
        int res=0;
        for(int i=100;i>=1;i--)
        {
            if(now<=0) break;
            res+=min(v[i],(now+i-1)/i);
            now-=i*min(v[i],(now+i-1)/i);
        }
        printf("%d ",res);
        v[t[o]]++;
        sum+=t[o];
    }
    printf("\n");
	return 0;
}