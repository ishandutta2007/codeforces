#include"bits/stdc++.h"
using namespace std;
char ans[55][55];
char s[55];
int a[55],nn;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",s);
        for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)ans[i][j]=0;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)
        {
            if(i==j)ans[i][j]='X';
            else ans[i][j]='=';
        }
        nn=0;
        for(int i=0;i<n;i++)if(s[i]=='2')a[nn++]=i;
        if(nn==2||nn==1)cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            if(nn)
            {
                a[nn++]=a[0];
                for(int i=1;i<nn;i++)ans[a[i-1]][a[i]]='+';
                for(int i=1;i<nn;i++)ans[a[i]][a[i-1]]='-';
            }
            for(int i=0;i<n;i++)printf("%s\n",ans[i]);
        }
    }
    return 0;
}