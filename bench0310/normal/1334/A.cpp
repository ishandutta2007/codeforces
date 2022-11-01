#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<int> p(n);
        vector<int> c(n);
        for(int i=0;i<n;i++) scanf("%d%d",&p[i],&c[i]);
        bool ok=1;
        if(p[0]<c[0]) ok=0;
        for(int i=1;i<n;i++)
        {
            int x=(p[i]-p[i-1]);
            int y=(c[i]-c[i-1]);
            if(x<0||y<0) ok=0;
            if(x<y) ok=0;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}