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
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++) scanf("%d",&b[i]);
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) if(a[i]!=b[i]) v.push_back({b[i]-a[i],i});
        bool ok=1;
        if(v.size()==1&&v[0].first<0) ok=0;
        for(int i=0;i<(int)v.size()-1;i++) if(v[i].first<0||v[i].second+1!=v[i+1].second||v[i].first!=v[i+1].first) ok=0;
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}