#include"bits/stdc++.h"
using namespace std;
char s[405][405];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
        }
        int x1=-1,x2,y1,y2;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)
        {
            if(s[i][j]=='*'&&x1!=-1)
            {
                x2=i;
                y2=j;
            }
            else if(s[i][j]=='*')
            {
                x1=i;
                y1=j;
            }
        }
        if(x1==x2)
        {
            if(x1==0)x2=1;
            else x2=0;
        }
        if(y1==y2)
        {
            if(y1==0)y2=1;
            else y2=0;
        }
        s[x1][y1]=s[x2][y2]=s[x2][y1]=s[x1][y2]='*';
        for(int i=0;i<n;i++)
        {
            printf("%s\n",s[i]);
        }
    }
    return 0;
}