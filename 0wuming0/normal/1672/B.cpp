#include"bits/stdc++.h"
using namespace std;
char s[200005];
int a[200005];
int b[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%s",s);
        int n=strlen(s);
        for(int i=0;s[i];i++)
        {
            a[i]=0;
            b[i]=0;
        }
        a[n]=b[n]=0;
        for(int i=0;s[i];i++)
        {
            if(s[i]=='A')a[i]++;
            else a[i]--;
        }
        if(s[n-1]=='A')
        {
            cout<<"no"<<endl;
            continue;
        }
        for(int i=0;i<n;i++)a[i]+=a[i-1];
        for(int i=0;i<n;i++)if(a[i]<0)
        {
            cout<<"no"<<endl;
            goto ne;
        }
        cout<<"yes"<<endl;
        ne:;
    }
    return 0;
}