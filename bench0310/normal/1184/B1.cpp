#include <bits/stdc++.h>

using namespace std;

int main()
{
	int s,b;
	scanf("%d%d",&s,&b);
	vector<int> a(s);
	for(int i=0;i<s;i++) scanf("%d",&a[i]);
	vector<pair<int,int>> v(b);
	for(int i=0;i<b;i++) scanf("%d%d",&v[i].first,&v[i].second);
	sort(v.begin(),v.end());
	int sum[b];
	sum[0]=v[0].second;
	for(int i=1;i<b;i++) sum[i]=sum[i-1]+v[i].second;
	for(int i=0;i<s;i++)
    {
        int l=-1,r=b;
        while(l<r-1)
        {
            int m=(l+r)/2;
            if(a[i]>=v[m].first) l=m;
            else r=m;
        }
        if(l!=-1) printf("%d ",sum[l]);
        else printf("0 ");
    }
    printf("\n");
	return 0;
}