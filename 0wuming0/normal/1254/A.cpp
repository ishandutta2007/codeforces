#include"bits/stdc++.h"
using namespace std;
int n,m,k;
char a[105][105];
int flag=1;
void nexts(int &i,int &j)
{
    if(m==1)
    {
        i++;
        return;
    }
    if(flag)
    {
        if(j==m)
        {
            i++;
            flag^=1;
        }
        else j++;
    }
    else
    {
        if(j==1)
        {
            i++;
            flag^=1;
        }
        else j--;
    }
}
void nextch(char &ch)
{
    if(ch=='9')ch='a';
    else if(ch=='z')ch='A';
    else if(ch=='Z')ch=0;
    else ch++;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        flag=1;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",a[i]+1);
        }
        for(int i=0;i<=n;i++)
        {
            a[i][0]=a[i][m+1]=0;
        }
        for(int i=0;i<=m;i++)
        {
            a[0][i]=a[n+1][i]=0;
        }
        int r=0;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        {
            if(a[i][j]=='R')r++;
        }
        int num=r/k,num1=r%k,num0=k-num1;
        int pp=0;//cout<<"ok"<<endl;
        char ch='0'-1;
        for(int i=1,j=1;;)
        {
            if(pp==0)
            {
                if(num0)
                {
                    num0--;
                    pp=num;
                    nextch(ch);
                }
                else if(num1)
                {
                    num1--;
                    pp=num+1;
                    nextch(ch);
                }
                else
                {
                    while(i<=n)
                    {
                        a[i][j]=ch;
                        nexts(i,j);
                    }
                    break;
                }
            }
            if(a[i][j]=='R')pp--;
            a[i][j]=ch;
            nexts(i,j);
        }
        for(int i=1;i<=n;i++)
        {
            printf("%s\n",a[i]+1);
        }
    }
    return 0;
}