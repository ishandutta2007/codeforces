#include"bits/stdc++.h"
using namespace std;
char s[200005];
//int l[200005];
int save[200005][26];
int ju(int x,int y)
{
    int k=0;
    for(int i=0;i<26;i++)
    {
        if(save[y][i]-save[x-1][i])k++;
    }//cout<<k<<endl;
    if(k>=3)return 1;
    else return 0;
}
int main()
{
    scanf("%s",s+1);/*
    int n=strlen(s+1);
    l[1]=0;
    int now=1;
    for(int i=1;i<=n;i++)
    {
        if(s[now]==s[i])l[i]=now;
        else
        {
            now=i;
            l[i]=now;
        }
    }*/
    for(int i=1;s[i];i++)
    {
        for(int j=0;j<26;j++)
        {
            save[i][j]=save[i-1][j];
        }
        save[i][s[i]-'a']++;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==y)printf("YES\n");
        else if(ju(x,y))printf("YES\n");
        //else if(x>=l[y])printf("NO\n");
        else if(s[x]!=s[y])printf("YES\n");
        else if(s[x]==s[y])printf("NO\n");
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}
/*
abc
1
1 3
*/