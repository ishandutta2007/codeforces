#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int h[n];
        for(int i=0;i<n;i++) scanf("%d",&h[i]);
        bool b=1;
        for(int i=0;i<n-1;i++)
        {
            m+=max(0,h[i]-max(0,h[i+1]-k));
            m-=max(0,max(0,h[i+1]-k)-h[i]);
            if(m<0) b=0;
        }
        if(b) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}