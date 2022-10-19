#include"bits/stdc++.h"
using namespace std;
int n,m;
char s[1000][1000];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
    }
    int i,j;
    for(i=0;i<n;i++)for(j=0;j<m;j++)
    {
        if(s[i][j]=='X')goto ne;
    }ne:;
    int ii=i,jj=j;
    while(s[i][jj]=='X')jj++;
    while(s[ii][j]=='X')ii++;
    for(int k=i;k<ii;k++)for(int l=j;l<jj;l++)
    {
        if(s[k][l]!='X')
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    int ans=(ii-i)*(jj-j);
    for(i=0;i<n;i++)for(j=0;j<m;j++)if(s[i][j]=='X')ans--;
    if(ans==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}