#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=2e5+1;
int a[101];
int main()
{
    int n,x,m,k=0,d=0,d2,k2;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        d2=0;
        k2=k;
        if (k2+x>m)
        {
            for (int j=100;j && k2+x>m;j--)
                for (int t=1;t<=a[j] && k2+x>m;t++)
                {
                    k2-=j;
                    d2++;
                }
        }
        k+=x;
        a[x]++;
        cout<<d+d2<<" ";
        if (k>m)
        {
            for (int j=100;j && k>m;j--)
                while (a[j]>0 && k>m)
                {
                    a[j]--;
                    k-=j;
                    d++;
                }
        }
    }
    return 0;
}