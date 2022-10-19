#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
unsigned long long x,y,l,r;

vector<unsigned long long> v;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("cond.in","r",stdin);
    //freopen("cond.out","w",stdout);
    cin>>x>>y>>l>>r;
    unsigned long long xx=1;
    for(int i=0;;++i)
    {
        if(xx>=r)
            break;
        unsigned long long yy=1;
        for(int j=0;;++j)
        {
            if(yy+xx>r)
                break;
            v.push_back(yy+xx);
            if(yy>r/y)
                break;
            yy*=y;
        }
        if(xx>r/x)
            break;
        xx*=x;
    }
    vector<unsigned long long> gg;
    for(int i=0;i<v.size();++i)
    {
        if(l<=v[i] && v[i]<=r)
            gg.push_back(v[i]);
    }
    gg.push_back(l-1);
    gg.push_back(r+1);
    sort(gg.begin(),gg.end());
    unsigned long long ans=0;
    for(int i=1;i<gg.size();++i)
        ans=max(ans,gg[i]-gg[i-1]);
    cout<<ans-1<<endl;
    return 0;
}