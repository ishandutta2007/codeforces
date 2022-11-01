#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int lim=100000;
	int q;
	scanf("%d",&q);
	while(q--)
    {
        int n;
        scanf("%d",&n);
        int l=-lim;
        int r=lim;
        int d=-lim;
        int u=lim;
        while(n--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int f[4];
            for(int i=0;i<4;i++) scanf("%d",&f[i]);
            if(!f[0]) l=max(l,x);
            if(!f[1]) u=min(u,y);
            if(!f[2]) r=min(r,x);
            if(!f[3]) d=max(d,y);
        }
        if(l<=r&&d<=u) printf("1 %d %d\n",r,u);
        else printf("0\n");
    }
	return 0;
}