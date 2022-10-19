#include"bits/stdc++.h"
using namespace std;
char s[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        cin>>s+1;
        int ans=0,c=0,d=0;
        vector<int>v;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='W')
            {
                ans++;
                if(s[i-1]=='W')ans++;
                if(d)
                {
                    v.push_back(d);
                    d=0;
                }
            }
            else
            {
                if(ans==0)c++;
                else d++;
            }
        }//cout<<ans<<endl;
        c+=d;//if(d)v.push_back(d);
        if(c==n)
        {
            if(k==0)cout<<0<<endl;
            else cout<<2*k-1<<endl;
            continue;
        }
        sort(v.begin(),v.end());
        int now=0;
        while(1)
        {//cout<<"<<"<<now<<" "<<v[now]<<endl;
            if(now!=v.size()&&k>=v[now])
            {
                k-=v[now];
                ans+=v[now++]*2+1;
            }
            else
            {
                if(now!=v.size())
                {
                    ans+=2*k;
                    break;
                }
                else
                {
                    ans+=2*min(c,k);
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}