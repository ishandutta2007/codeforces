#include <bits/stdc++.h>
using namespace std;
const int N=102;

int n,k;

int a[N][N];

int main()
{
    cin>>n>>k;
    if(k>n*n)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(a[i][j]==1)
                continue;
            if(i==j)
            {
                if(k-1>=0)
                {
                    k--;
                    a[i][j]=1;
                }
            }
            else
            {
                if(k-2>=0)
                {
                    k-=2;
                    a[i][j]=1;
                    a[j][i]=1;
                }
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}