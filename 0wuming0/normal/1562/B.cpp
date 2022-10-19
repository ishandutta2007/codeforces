#include"bits/stdc++.h"
using namespace std;
char s[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",s);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='2'||s[i]=='3'||s[i]=='5'||s[i]=='7')continue;
            cout<<1<<endl;
            cout<<s[i]<<endl;
            goto ne;
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]=='2')for(int j=i+1;j<n;j++)if(s[j]=='2'||s[j]=='5'||s[j]=='7')
            {
                cout<<2<<endl;
                cout<<s[i]<<s[j]<<endl;
                goto ne;
            }
            if(s[i]=='3')for(int j=i+1;j<n;j++)if(s[j]=='2'||s[j]=='3'||s[j]=='5')
            {
                cout<<2<<endl;
                cout<<s[i]<<s[j]<<endl;
                goto ne;
            }
            if(s[i]=='5')for(int j=i+1;j<n;j++)if(s[j]=='2'||s[j]=='5'||s[j]=='7')
            {
                cout<<2<<endl;
                cout<<s[i]<<s[j]<<endl;
                goto ne;
            }
            if(s[i]=='7')for(int j=i+1;j<n;j++)if(s[j]=='2'||s[j]=='5'||s[j]=='7')
            {
                cout<<2<<endl;
                cout<<s[i]<<s[j]<<endl;
                goto ne;
            }
        }
        ne:;
    }
    return 0;
}