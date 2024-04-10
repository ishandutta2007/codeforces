#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int> b;
	long long res=0;
	for(int i=0;i<n;i++)
    {
        int temp;
        scanf("%d",&temp);
        res+=(long long)temp*m;
        b.push_back(temp);
    }
    sort(b.begin(),b.end());
    int mn=100000000;
    vector<int> used(n,0);
    for(int i=0;i<m;i++)
    {
        int temp;
        scanf("%d",&temp);
        mn=min(mn,temp);
        int l=-1,r=n;
        while(l<r-1)
        {
            int mid=(l+r)/2;
            if(b[mid]<=temp) l=mid;
            else r=mid;
        }
        if(b[l]!=temp) while(l>=0&&used[l]==m-1) l--;
        if(l==-1)
        {
            printf("-1\n");
            return 0;
        }
        if(b[l]<temp)
        {
            res+=(long long)temp-b[l];
            used[l]++;
        }
    }
    if(mn<b[n-1])
    {
        printf("-1\n");
        return 0;
    }
    printf("%I64d\n",res);
	return 0;
}