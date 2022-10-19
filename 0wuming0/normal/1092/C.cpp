#include"bits/stdc++.h"
using namespace std;
char s[205][105];
int len[205];
int vis[205];
char ans[205];
vector<int>save;
int ok(char s1[],char s2[])
{
    for(int i=0;s2[i];i++)
    {
        if(s1[i]!=s2[i])
        {
            return 0;
        }
    }
    return 1;
}
void solve(char s1[],char s2[],char &k)
{
    for(int i=0;s2[i];i++)
    {
        if(s1[i]!=s2[i])
        {
            k='S';
            return ;
        }
    }
    if(vis[strlen(s2)]==0)
    {
        k='P';
        vis[strlen(s2)]=1;
    }
    else k='S';
}
int main()
{
    int n;
    cin>>n;
    int sum=2*(n-1);
    for(int i=0;i<sum;i++)
    {
        scanf("%s",s[i]);
        len[i]=strlen(s[i]);
        if(len[i]==n-1)save.push_back(i);
    }
    int num1=save[0],num2=save[1];
    int k;
    int s1=0,s2=0;
    if(ok(s[num1],s[num2]+1)==1&&ok(s[num2],s[num1]+1)==0)
    {
        num1=num2;
        goto neee;
    }
    if(ok(s[num2],s[num1]+1)==1&&ok(s[num1],s[num2]+1)==0)
    {
        //num1=num2;
        goto neee;
    }
    for(k=0;k<n-1;k++)
    {
        if(s[num1][k]!=s[num2][k])break;
    }
    for(int i=0;i<sum;i++)if(len[i]>k)
    {
        if(s[num1][k]==s[i][k])s1++;
        if(s[num2][k]==s[i][k])s2++;
    }
    if(s1>s2)ans[num1]='P',ans[num2]='S';
    else
    {
        ans[num1]='S',ans[num2]='P';
        num1=num2;
    }
    neee:;
    for(int i=0;i<sum;i++)
    {
        solve(s[num1],s[i],ans[i]);
    }
    printf("%s\n",ans);
    return 0;
}
/*
4
aaa
aaa
aa
a
aa
a
*/