#include <bits/stdc++.h>
using namespace std;
const int N=100005;
struct ban
{
    long long x,y;
};

int n;
ban a[N];

bool stg(ban t1,ban t2,ban t)
{
    return (t1.x-t.x)*(t1.y-t2.y)==(t1.x-t2.x)*(t1.y-t.y);
}

bool stgg(const vector<ban>& v)
{
    if(v.size()<=2)
        return true;
    for(int i=0;i<v.size();++i)
        if(!stg(v[0],v[1],v[i]))
            return false;
    return true;
}

bool stggg(int x,int y)
{
    vector<bool> c;
    c.assign(n,false);
    vector<ban> v;
    for(int i=0;i<n;++i)
    {
        if(stg(a[y],a[x],a[i]))
            c[i]=true;
        else
            v.push_back(a[i]);
    }
    return (stgg(v));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i].x>>a[i].y;
    if(n<=3 || stggg(0,1) || stggg(0,2) || stggg(1,2))
    {
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}