#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        set<int>s;
        for(int i=0;i<n;i++)
        {
            int c;
            cin>>c;
            s.insert(c);
        }
        auto it=s.end();
        it--;
        int l=0,r=*it;
        for(auto a:s)
        {
            if(a==l)l++;
            else if(a>l)break;
        }
        int add=0;
        while(k--)
        {//cout<<l<<" "<<r<<endl;
            if(r+1==l)
            {
                add=k+1;
                break;
            }
            int now=(l+r+1)/2;
            if(s.end()!=s.find(now))break;
            s.insert(now);
            if(now>r)r=now;
            if(l==now)
            {
                l=0;
                for(it=s.find(now);it!=s.end();it++)
                {
                    if(*it==l)l++;
                    else if(*it>l)break;
                }
            }
        }
        cout<<add+s.size()<<endl;
    }
    return 0;
}