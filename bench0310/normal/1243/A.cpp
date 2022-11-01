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
        vector<int> v(n);
        for(int i=0;i<n;i++) scanf("%d",&v[i]);
        sort(v.begin(),v.end(),greater<int>());
        int res=0;
        for(int i=0;i<n;i++) if(v[i]>=i+1) res=i+1;
        printf("%d\n",res);
    }
    return 0;
}