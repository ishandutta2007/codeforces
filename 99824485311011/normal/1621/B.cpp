#include<bits/stdc++.h>
using namespace std;
int T,n,l[100010],r[100010],c[100010];
set<pair<int,int> > stl,str;
set<pair<pair<int,int>,int> > seg;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        stl.clear();str.clear();seg.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&l[i],&r[i],&c[i]);
            stl.insert(make_pair(l[i],c[i]));
            str.insert(make_pair(r[i],-c[i]));
            seg.insert(make_pair(make_pair(l[i],r[i]),c[i]));
            int cl=stl.begin()->first,cr=(--str.end())->first,cst=stl.begin()->second-(--str.end())->second;
            set<pair<pair<int,int>,int> >::iterator it=seg.lower_bound(make_pair(make_pair(cl,cr),0));
            if(it!=seg.end()&&it->first==make_pair(cl,cr))cst=min(cst,it->second);
            printf("%d\n",cst);
        }
    }
    return 0;
}