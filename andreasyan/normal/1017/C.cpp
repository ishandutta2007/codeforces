#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=100005,M=1000000007;

int n;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("river.in","r",stdin);
    //freopen("river.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i)
        a[i]=i+1;
    for(int i=sqrt(n);i<=sqrt(n);++i)
    {
        int m=0;
        int z=0;
        for(int j=i;;j+=i)
        {
            for(int k=j;k>m;--k)
            {
                if(k<=n)
                    a[k]=++z;
            }
            if(j>=n)
                break;
            m=j;
        }
        for(int j=1;j<=n;++j)
            cout<<a[j]<<' ';
        cout<<endl;
    }
    return 0;
}