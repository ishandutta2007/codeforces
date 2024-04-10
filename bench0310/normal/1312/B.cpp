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
        for(int i=0;i<n;i++) printf("%d%c",v[i]," \n"[i==n-1]);
    }
    return 0;
}