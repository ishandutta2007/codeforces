#include"bits/stdc++.h"
#define ll long long
using namespace std;
int a[5000];
int solve(int n,int &num,int sum,int x)
{
    if(n*x==sum){num=n;return 0;}
    if(num==0){num=n-1;return 0;}
    if(num){num=n;return 0;}
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        for(int i=0;i<n;i++)scanf("%d",a+i);
        int sum=0,num=0,ans=0;
        for(int i=0;i<n;i++)sum+=a[i];
        for(int i=0;i<n;i++)if(x==a[i])num++;
        if(n==num)cout<<"0"<<endl;
        else if(num==0&&sum!=n*x)cout<<"2"<<endl;
        else cout<<"1"<<endl;
        /*
        while(num!=n)
        {
            solve(n,num,sum,x);
            ans++;
        }
        cout<<ans<<endl;*/
        //
    }
    return 0;
}
/*
3

6 4
4 4 4 4 4 4

9 38
33 3 3 3 3 3 38 33 39

2 69
68 70
*/