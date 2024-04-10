#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=102;

int n;
char a[N];

int u,t;

int ans;
void stg(int u,int t)
{
    int yans=0;
    while(1)
    {
        if(u>=1 && t>=10)
        {
            yans++;
            u--;
            t-=10;
        }
        else
            break;
    }
    ans=max(ans,yans);
}

int main()
{
    //freopen("input.txt","r",stdin);
    cin>>n;
    cin>>a;
    for(int i=0;i<n;++i)
    {
        if(a[i]=='8')
            ++u;
        else
            ++t;
    }
    for(int i=1;i<=u;++i)
    {
        stg(i,t+u-i);
    }
    cout<<ans<<endl;
    return 0;
}