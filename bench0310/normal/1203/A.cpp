#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
    {
        int n;
        scanf("%d",&n);
        int p[n];
        int a,b;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&p[i]);
            if(p[i]==1) a=i;
            if(p[i]==n) b=i;
        }
        bool res=0;
        bool ok=1;
        for(int i=a;(i+1)%n!=a;i=(i+1)%n)
        {
            if(p[i]+1!=p[(i+1)%n]) ok=0;
        }
        if(ok) res=1;
        ok=1;
        for(int i=b;(i+1)%n!=b;i=(i+1)%n)
        {
            if(p[i]-1!=p[(i+1)%n]) ok=0;
        }
        if(ok) res=1;
        if(res) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}