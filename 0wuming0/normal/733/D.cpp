#include"bits/stdc++.h"
using namespace std;
int ans;
vector<int>v;
map<pair<int,int>,pair<int,int> >mp;
void fd(int a,int b,int c,int i)
{
    if(a>b)swap(a,b);
    auto it=mp.find(pair<int,int>(a,b));
    if(it!=mp.end())
    {
        if(min(min(c+(it->second).first,a),b)>ans)
        {
            ans=min(min(c+(it->second).first,a),b);
            v.clear();
            v.push_back((it->second).second);
            v.push_back(i);
        }
    }
}
void add(int a,int b,int c,int i)
{
    if(a>b)swap(a,b);
    mp[pair<int,int>(a,b)]=max(mp[pair<int,int>(a,b)],pair<int,int>(c,i));
}
int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(min(min(a,b),c)>ans)
        {
            ans=min(min(a,b),c);
            v.clear();
            v.push_back(i);
        }
        fd(a,b,c,i);
        fd(b,c,a,i);
        fd(c,a,b,i);
        add(a,b,c,i);
        add(b,c,a,i);
        add(c,a,b,i);
    }
    cout<<v.size()<<endl;
    if(v.size()==1)cout<<v[0]<<endl;
    else cout<<v[0]<<" "<<v[1]<<endl;
    return 0;
}