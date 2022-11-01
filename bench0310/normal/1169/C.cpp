#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> a(300000);

bool solve(int x)
{
    vector<int> b=a;
    if(b[0]+x>=m)  b[0]=0;
    for(int i=1;i<n;i++)
    {
        if(b[i]<=b[i-1])
        {
            if(b[i]+x<b[i-1]) return 0;
            b[i]=b[i-1];
        }
        else
        {
            if((b[i]+x>=m)&&(b[i]+x)%m>=b[i-1]) b[i]=b[i-1];
        }
    }
    return 1;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	int l=-1,r=m;
	while(l<r-1)
    {
        int mid=(l+r)/2;
        if(solve(mid)) r=mid;
        else l=mid;
    }
    printf("%d\n",r);
	return 0;
}