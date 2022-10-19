#include"bits/stdc++.h"
using namespace std;
char s[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int ok=1;
        scanf("%s",s);
        for(int i=0,j=n-1;i<j;i++,j--)if(s[i]!=s[j])ok=0;
        if(k==0||ok==1)cout<<1<<endl;
        else cout<<2<<endl;
    }
    return 0;
}