#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n][m];
    for(int o=0;o<n;o++) for(int i=0;i<m;i++) scanf("%d",&a[o][i]);
    int res=0;
    for(int i=0;i<m;i++)
    {
        vector<int> v(n,0);
        for(int o=0;o<n;o++)
        {
            if(a[o][i]<=n*m&&(a[o][i]%m)==((i+1)%m))
            {
                int t=(a[o][i]+m-1)/m-1;
                if(t<=o) v[o-t]++;
                else v[o+n-t]++;
            }
        }
        int b=n;
        for(int o=0;o<n;o++) b=min(b,o+n-v[o]);
        res+=b;
    }
    printf("%d\n",res);
    return 0;
}