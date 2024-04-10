#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n=997;
    for(int i=2;i<n;i++)if(n%i==0)cout<<i<<endl;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int wo=(997-n+1);
        int my=1;
        if(wo%2)wo-=3,my+=3;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int ans;
                if(i==j)ans=wo;
                else if((i-j+n)%n==1)ans=my;
                else ans=1;
                printf("%d%c",ans," \n"[j==n-1]);
            }
        }
    }
    return 0;
}