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
        map<int,int> m;
        bool res=0;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            if(m.find(a)!=m.end())
            {
                if(m[a]!=i-1) res=1;
            }
            else m[a]=i;
        }
        if(res) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}