#include <bits/stdc++.h>

using namespace std;

char id(int a)
{
    if(a<26) return ('a'+a);
    else if(a<52) return ('A'+(a-26));
    else return ('0'+(a-52));
}

pair<int,int> step(int a,int b,int r,int c)
{
    if(!(a&1)) //right
    {
        if(b<c-1) return {a,b+1};
        else return {a+1,b};
    }
    else
    {
        if(b>0) return {a,b-1};
        else return {a+1,b};
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int r,c,k;
        scanf("%d%d%d",&r,&c,&k);
        char s[r][c+1];
        for(int o=0;o<r;o++) scanf("%s",s[o]);
        int cnt=0;
        for(int o=0;o<r;o++) for(int i=0;i<c;i++) cnt+=(s[o][i]=='R');
        int num=cnt/k;
        int add=cnt%k;
        int a=0,b=0;
        int rice=0;
        int idx=0;
        char res[r][c+1];
        for(int o=0;o<r;o++) res[o][c]='\0';
        while(a<r)
        {
            res[a][b]=id(min(idx,k-1));
            if(s[a][b]=='R') rice++;
            if(rice==num+(add>0))
            {
                rice=0;
                idx++;
                add--;
            }
            tie(a,b)=step(a,b,r,c);
        }
        for(int o=0;o<r;o++) printf("%s\n",res[o]);
    }
    return 0;
}