#include"bits/stdc++.h"
using namespace std;
int a[10005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,u,v;
        cin>>n>>u>>v;
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
        }
        for(int i=1;i<n;i++)
        {
            if(abs(a[i]-a[i-1])>1)
            {cout<<0<<endl;goto ne;
            }
        }
        for(int i=1;i<n;i++)
        {
            if(a[i]!=a[0])
            {cout<<min(u,v)<<endl;goto ne;
            }
        }
        cout<<min(u,v)+v<<endl;
        ne:;
    }
    return 0;
}
/*
3
2 3 4
2000 2000
2 3 4
3 2
2 4 3
3 2
*/