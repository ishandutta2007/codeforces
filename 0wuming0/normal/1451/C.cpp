#include"bits/stdc++.h"
using namespace std;
char a[1000006],b[1000006];
int numa[400],numb[400];
int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        for(int i='a';i<='z';i++)numa[i]=numb[i]=0;
        cin>>n>>k;
        scanf("%s%s",a,b);
        int sum=0,m=0;
        for(int i=0;i<n;i++)
        {
            numa[a[i]]++;
            numb[b[i]]++;
        }
        for(int i='a';i<='z';i++)
        {
            if(numa[i]<numb[i])
            {
                printf("No\n");
                goto nt;
            }
            int mov=(numa[i]-numb[i])/k*k;
            //cout<<i<<" "<<mov<<endl;
            numa[i]-=mov;
            numa[i+1]+=mov;
            if(numa[i]!=numb[i])
            {
                printf("No\n");
                goto nt;
            }
            if(i=='z')
            {
                printf("Yes\n");
                goto nt;
            }
        }
        nt:;
    }
    return 0;
}