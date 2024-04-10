#include <bits/stdc++.h>
using namespace std;
const int N=37;

int n,m;
vector<int> v1,v2;

vector<int> a,b;

int main()
{
    cin>>n>>m;
    for(int i=0;i<n/2;++i)
    {
        int x;
        cin>>x;
        v1.push_back(x);
    }
    for(int i=n/2;i<n;++i)
    {
        int x;
        cin>>x;
        v2.push_back(x);
    }
    for(int x=0;x<(1<<v1.size());++x)
    {
        int g=0;
        for(int i=0;i<v1.size();++i)
        {
            if(((1<<i)&x))
            {
                g+=v1[i];
                g%=m;
            }
        }
        a.push_back(g);
    }
    for(int x=0;x<(1<<v2.size());++x)
    {
        int g=0;
        for(int i=0;i<v2.size();++i)
        {
            if(((1<<i)&x))
            {
                g+=v2[i];
                g%=m;
            }
        }
        b.push_back(g);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    sort(b.begin(),b.end());
    int j=-1;
    int ans=0;
    for(int i=0;i<a.size();++i)
    {
        while(1)
        {
            if(j==b.size()-1)
                break;
            if(b[j+1]<(m-a[i]))
                ++j;
            else
                break;
        }
        ans=max(ans,a[i]+b[j]);
        if(j!=b.size()-1)
            ans=max(ans,a[i]+b.back()-m);
    }
    cout<<ans<<endl;
	return 0;
}