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
        vector<int> a(n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        vector<bool> v(n-1,0);
        for(int o=1;o<=n;o++)
        {
            int idx=distance(a.begin(),find(a.begin(),a.end(),o));
            while(idx>0&&v[idx-1]==0&&a[idx-1]>a[idx])
            {
                swap(a[idx-1],a[idx]);
                v[--idx]=1;
            }
        }
        for(int i=0;i<n;i++) printf("%d%c",a[i]," \n"[i==n-1]);
    }
    return 0;
}