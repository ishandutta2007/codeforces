#include <bits/stdc++.h>
using namespace std;
const int N=1003;

int n,a,b;

int ans[N][N];

bool stg()
{
    if(a>1 && b>1)
        return false;
    if(a>1 && b==1)
    {
        int k=n;
        for(int i=2;i<=n;++i)
        {
            if(k==a)
                break;
            ans[1][i]=1;
            ans[i][1]=1;
            --k;
        }
        return true;
    }
    if(a==1 && b>1)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(i!=j)
                    ans[i][j]=1;
            }
        }
        int k=n;
        for(int i=2;i<=n;++i)
        {
            if(k==b)
                break;
            ans[1][i]=0;
            ans[i][1]=0;
            --k;
        }
        return true;
    }
    if(a==1 && b==1)
    {
        if(n==1)
            return true;
        if(n<=3)
            return false;
        for(int i=1;i<n;++i)
        {
            ans[i][i+1]=1;
            ans[i+1][i]=1;
        }
        return true;
    }
}

int main()
{
    cin>>n>>a>>b;
    if(stg())
    {
        cout<<"YES"<<endl;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
                cout<<ans[i][j];
            cout<<endl;
        }
    }
    else
        cout<<"NO"<<endl;
    return 0;
}