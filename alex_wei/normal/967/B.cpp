#include<bits/stdc++.h>
using namespace std;
double n,a,b,s[100100],s1,sum;
int main()
{
    cin>>n>>a>>b>>s1,sum=s1;
    for(int x=2;x<=n;x++)cin>>s[x],sum+=s[x];
    sort(s+2,s+(int)n+1);
    for(int x=n;x>=1;x--){
        if(a*s1/sum>=b){cout<<n-x;return 0;}
        sum-=s[x];
    }
    return 0;
}