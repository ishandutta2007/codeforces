#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=300005,INF=999999999;

int n;
priority_queue<int> a,b;

int main()
{
    //freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        a.push(x);
    }
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        b.push(x);
    }
    long long ans=0;
    n*=2;
    int z=0;
    while(n--)
    {
        if(z==0)
        {
            if(a.empty())
                b.pop();
            else if(b.empty())
            {
                ans+=a.top();
                a.pop();
            }
            else
            {
                if(a.top()>b.top())
                {
                    ans+=a.top();
                    a.pop();
                }
                else
                    b.pop();
            }
        }
        else
        {
            if(a.empty())
            {
                ans-=b.top();
                b.pop();
            }
            else if(b.empty())
                a.pop();
            else
            {
                if(a.top()>b.top())
                    a.pop();
                else
                {
                    ans-=b.top();
                    b.pop();
                }
            }
        }
        z^=1;
    }
    cout<<ans<<endl;
    return 0;
}