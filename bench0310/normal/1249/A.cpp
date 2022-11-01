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
        vector<int> v(n);
        for(int i=0;i<n;i++) scanf("%d",&v[i]);
        sort(v.begin(),v.end());
        int t=0;
        for(int i=0;i<n-1;i++) if(v[i]+1==v[i+1]) t=1;
        printf("%d\n",t+1);
    }
    return 0;
}