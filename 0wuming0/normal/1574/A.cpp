#include"bits/stdc++.h"
using namespace std;
char s[10005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<n;j++)s[j]='(';
            for(int j=n;j<2*n;j++)s[j]=')';
            s[2*n]=0;
            swap(s[i],s[n]);
            printf("%s\n",s);
        }
    }
    return 0;
}