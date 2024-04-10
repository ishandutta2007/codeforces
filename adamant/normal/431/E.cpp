#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma pack(1)

using namespace std;
using namespace __gnu_pbds;

#define TASK "test"
#define ll long long

template<class Node_CItr,
class Node_Itr,
class Cmp_Fn,
class _Alloc>
struct my_node_update
{
    typedef pair<ll,ll> metadata_type;
    virtual Node_CItr node_begin() const=0;
    virtual Node_CItr node_end() const=0;

    double get(ll k)
    {
        auto it=node_begin();
        ll sum=0,num=0;
        while(it!=node_end())
        {
            auto l=it.get_l_child();
            auto r=it.get_r_child();
            ll Ts=sum;
            ll Tn=num;
            if(l!=node_end())
            {
                Tn+=l.get_metadata().first;
                Ts+=l.get_metadata().second;
            }
            if((*it)->first*Tn>=Ts+k)
            {
                it=it.get_l_child();
            }
            else
            {
                sum=Ts+(*it)->first;
                num=Tn+1;
                it=it.get_r_child();
            }
        }
        return 1.*(sum+k)/num;

    }

    void operator()(Node_Itr it, Node_CItr it_end)
    {
        auto l=it.get_l_child();
        auto r=it.get_r_child();
        pair<ll,ll> left={0,0},right={0,0};
        if(l!=it_end) left =l.get_metadata();
        if(r!=it_end) right=r.get_metadata();
        (pair<ll,ll>&) it.get_metadata()={left.first+right.first+1,left.second+right.second+(*it)->first};
    }
};

tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,my_node_update> me;

main()
 {
    #ifndef ONLINE_JUDGE
    freopen(TASK".in","r",stdin);
    freopen(TASK".out","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<int> s(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        me.insert({s[i],i});
    }

    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int p,x;
            cin>>p>>x;
            me.erase({s[p-1],p-1});
            s[p-1]=x;
            me.insert({s[p-1],p-1});
        }
        else
        {
            ll v;
            cin>>v;
            cout<<me.get(v)<<"\n";
        }
    }

 }