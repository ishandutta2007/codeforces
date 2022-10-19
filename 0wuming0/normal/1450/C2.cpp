#include"bits/stdc++.h"
using namespace std;
char s[305][305];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)scanf("%s",s[i]);
        int a1=0,a2=0,a3=0,b1=0,b2=0,b3=0;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)
        {
            switch((i-j+600)%3+1)
            {
                case 1:if(s[i][j]=='O')b1++;if(s[i][j]=='X')a1++;break;
                case 2:if(s[i][j]=='O')b2++;if(s[i][j]=='X')a2++;break;
                case 3:if(s[i][j]=='O')b3++;if(s[i][j]=='X')a3++;break;
            }
        }
        int O,X;
        if(a1+b1>=a2+b2&&a1+b1>=a3+b3)
        {
            if(a2+b3>=a3+b2)
            {
                O=3;X=2;
            }
            else
            {
                O=2;X=3;
            }
        }
        else if(a2+b2>=a3+b3)
        {
            if(a1+b3>=a3+b1)
            {
                O=3;X=1;
            }
            else
            {
                O=1;X=3;
            }
        }
        else
        {
            if(a2+b1>=a1+b2)
            {
                O=1;X=2;
            }
            else
            {
                O=2;X=1;
            }
        }
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)
        {
            switch((i-j+600)%3+1)
            {
                case 1:if(O==1&&s[i][j]!='.')s[i][j]='O';if(X==1&&s[i][j]!='.')s[i][j]='X';break;
                case 2:if(O==2&&s[i][j]!='.')s[i][j]='O';if(X==2&&s[i][j]!='.')s[i][j]='X';break;
                case 3:if(O==3&&s[i][j]!='.')s[i][j]='O';if(X==3&&s[i][j]!='.')s[i][j]='X';break;
            }
        }
        for(int i=0;i<n;i++)printf("%s\n",s[i]);
    }
    return 0;
}