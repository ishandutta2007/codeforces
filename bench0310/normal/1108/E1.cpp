#include <bits/stdc++.h>

using namespace std;

bool in(int l,int r,int a)
{
    if(a>=l&&a<=r) return 1;
    else return 0;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    pair<int,int> p[m];
    for(int i=0;i<m;i++) scanf("%d %d",&p[i].first,&p[i].second);
    vector<int> v;
    int best=-1;
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<n;i++)
        {
            int res=arr[o]-arr[i];
            vector<int> t;
            for(int j=0;j<m;j++)
            {
                if(in(p[j].first-1,p[j].second-1,i))
                {
                    t.push_back(j);
                    res+=(1-in(p[j].first-1,p[j].second-1,o));
                }
            }
            if(res>best)
            {
                best=res;
                v=t;
            }
        }
    }
    printf("%d\n",best);
    printf("%d\n",v.size());
    for(int i=0;i<(int)v.size();i++) printf("%d ",v[i]+1);
    printf("\n");
    return 0;
}