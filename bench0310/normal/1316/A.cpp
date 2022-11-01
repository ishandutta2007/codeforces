#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        vector<int> v(n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&v[i]);
            sum+=v[i];
        }
        printf("%d\n",min(m,sum));
    }
    return 0;
}