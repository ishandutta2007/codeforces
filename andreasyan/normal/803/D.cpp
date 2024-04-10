#include <bits/stdc++.h>
using namespace std;

int k;
vector<vector<int> > a;

bool stg(int x)
{
    if(x==8)
        cout<<"";
    int t=0;
    int e=0;
    for(int i=0;i<a.size();++i)
    {
        int p=0;
        for(int j=0;j<a[i].size();++j)
        {
            if(e+p+a[i][j]<=x)
            {
                p+=a[i][j];
            }
            else
            {
                ++t;
                e=0;
                p=a[i][j];
                if(p>x)
                    return false;
            }
        }
        if(e+p<=x)
            e+=p;
        else
        {
            ++t;
            e=0;
            if(p>x)
                return false;
        }
    }
    ++t;
    return t<=k;
}

int byn()
{
    int l=1,r=1000006;
    while((r-l)>4)
    {
        int m=(l+r)/2;
        if(stg(m))
            r=m;
        else
            l=m;
    }
    for(int i=l;i<=r;++i)
        if(stg(i))
            return i;
}

int main()
{
    cin>>k;
    string s;
    while(cin>>s)
    {
        vector<int> v;
        int q=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='-')
            {
                v.push_back(q);
                q=0;
            }
            else
                ++q;
        }
        v.push_back(q);
        a.push_back(v);
    }
    for(int i=0;i<a.size();++i)
    {
        for(int j=0;j<a[i].size();++j)
            a[i][j]++;
    }
    a[a.size()-1][a[a.size()-1].size()-1]--;
    cout<<byn()<<endl;
    return 0;
}