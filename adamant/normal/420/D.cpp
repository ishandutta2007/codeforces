#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define p(i,j) pair<i,j>
#define v(i) vector<i>
#define x first
#define y second

typedef tree<
p(int,p(int,int)),
null_type,
less<p(int,p(int,int))>,
rb_tree_tag,
tree_order_statistics_node_update> order_set;

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    order_set t;
    for(int i=0;i<n;i++)
        t.insert({i,{i,-1}});
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        auto it=t.find_by_order(y-1);
        if(it->y.y!=-1 && it->y.y!=x)
        {
            cout<<-1<<endl;
            return 0;
        }
        t.insert({t.begin()->x-1,{it->y.x,x}});
        t.erase(it);
    }
    v(bool) used(n,0);
    for(auto it:t)
        if(it.y.y!=-1)
        {
            if(used[it.y.y-1])
            {
                cout<<-1<<endl;
                return 0;
            }
            used[it.y.y-1]=1;
        }
    v(int) unused;
    for(int i=0;i<n;i++)
        if(!used[i])
        unused.push_back(i+1);
    int cur=0;
    v(int) ans(n);

    for(auto it:t)
        if(it.y.y!=-1)
            ans[it.y.x]=it.y.y;
        else
            ans[it.y.x]=unused[cur++];
for(int i:ans)cout<<i<<' ';
}