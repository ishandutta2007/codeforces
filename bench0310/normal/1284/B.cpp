#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    long long one=0; //not containing an ascent
    vector<int> a; //min
    vector<int> b; //max
    long long two=0; //containing an ascent
    for(int o=0;o<n;o++)
    {
        int m;
        scanf("%d",&m);
        vector<int> v;
        v.resize(m);
        int t=1000000;
        int u=0;
        bool asc=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&v[i]);
            if(t<v[i]) asc=1;
            t=min(t,v[i]);
            u=max(u,v[i]);
        }
        if(asc==0)
        {
            one++;
            a.push_back(t);
            b.push_back(u);
        }
        else two++;
    }
    sort(b.begin(),b.end());
    long long res=two*two+2*one*two;
    for(int t:a)
    {
        int l=-1,r=b.size();
        while(l<r-1)
        {
            int m=(l+r)/2;
            if(b[m]>t) r=m;
            else l=m;
        }
        res+=(b.size()-r);
    }
    printf("%I64d\n",res);
    return 0;
}