#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        char s[105];
        cin>>s;
        int ans=0;
        for(int i=0,j=n-1;i+1<j;i++,j--)
        {
            if(s[i]==s[j])ans++;
            else break;
        }
        if(ans>=k)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}