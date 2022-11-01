#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,x;
        scanf("%d%d",&n,&x);
        vector<bool> v(n+x+2,0);
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            v[a]=1;
        }
        int idx=1;
        while(v[idx]) idx++;
        while(x--)
        {
            v[idx]=1;
            while(v[idx]) idx++;
        }
        printf("%d\n",idx-1);
    }
    return 0;
}