#include<bits/stdc++.h>  
using namespace std;
int n,m,a[102],cnt;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=n;i>0;i--){
        a[i]+=a[i+1];
        if(a[i]>=m)cout<<n-i+1,exit(0);
    }
    return 0;
}