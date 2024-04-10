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
        int m=n;
        vector<pair<int,int>> v;
        for(int i=2;i*i<=m;i++)
        {
            if((m%i)==0) v.push_back({i,0});
            while((m%i)==0)
            {
                v.back().second++;
                m/=i;
            }
        }
        if(m>1) v.push_back({m,1});
        bool ok=1;
        int a,b,c;
        if(v.size()==1)
        {
            if(v[0].second>=6)
            {
                a=v[0].first;
                b=v[0].first*v[0].first;
                c=n/(v[0].first*v[0].first*v[0].first);
            }
            else ok=0;
        }
        else if(v.size()==2)
        {
            if(v[0].second+v[1].second<=3) ok=0;
            else
            {
                a=v[0].first;
                b=v[1].first;
                c=n/(v[0].first*v[1].first);
            }
        }
        else
        {
            a=v[0].first;
            b=v[1].first;
            c=n/(v[0].first*v[1].first);
        }
        if(ok) printf("YES\n%d %d %d\n",a,b,c);
        else printf("NO\n");
    }
    return 0;
}