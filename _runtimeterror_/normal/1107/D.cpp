#include<iostream>

using namespace std;

const int N = 5205;

int a[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    auto hex = [&](char c)
    {
        if(c>='0' && c<='9')
            return c-'0';
        return c-'A'+10;
    };
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;j+=4)
        {
            char c;
            cin>>c;
            int x = hex(c);
            a[i][j+3]=x&1;
            a[i][j+2]=(x&2)>0;
            a[i][j+1]=(x&4)>0;
            a[i][j]=(x&8)>0;
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    int ans = 0;
    auto f = [&](int x)
    {
        for(int i=1;i<=n;i+=x)
        {
            for(int j=1;j<=n;j+=x)
            {
                int l = a[i+x-1][j+x-1];
                l -= a[i-1][j+x-1];
                l -= a[i+x-1][j-1];
                l += a[i-1][j-1];
                if(l!=0 && l!=x*x)
                    return false;
            }
        }
        return true;
    };
    for(int i=1;i<=n;++i)
    {
        if(n%i==0 && f(i))
        {
            ans = max(ans,i);
        }
    }
    cout<<ans;
}