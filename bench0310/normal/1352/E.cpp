#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<int> a(n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        vector<bool> v(n*n+1,0);
        for(int o=0;o<n;o++)
        {
            int x=a[o];
            for(int i=o+1;i<n;i++)
            {
                x+=a[i];
                v[x]=1;
            }
        }
        int res=0;
        for(int i=0;i<n;i++) res+=v[a[i]];
        printf("%d\n",res);
    }
    return 0;
}