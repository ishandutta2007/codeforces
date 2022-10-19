#include"bits/stdc++.h"
using namespace std;
char s[1000005];
char t[1000005];
#define next nextttt
int next[1000005];
int main()
{
    int q,n;
    cin>>q;
    scanf("%s",s);
    n=strlen(s);
    for(int i=1;i<q;i++)
    {
        scanf("%s",t);
        int len=strlen(t);
        if(len==1)
        {
            if(s[n-1]!=t[0])s[n++]=t[0],s[n]=0;
            continue;
        }
        next[0]=-1;
        next[1]=0;
        for(int i=2;t[i-1];i++)for(int j=0;j!=-1;j=next[j],next[i]=0)while(t[i-1]==t[j])next[i++]=++j;
        //for(int i=0;i<=len+1;i++)cout<<next[i]<<endl;
        for(int i=max(n-len,0),j=0;;i++,j++)
        {
            if(s[i]==0)
            {
                /*sprintf(s+i,"%s",t+j);
                n+=len-j;*/
                for(;t[j];i++,j++)
                {
                    s[i]=t[j];
                    n++;
                }
                break;
            }
            cmp:;
            if(s[i]!=t[j])
            {
                j=next[j];
                if(j!=-1)goto cmp;
            }
        }
    }
    printf("%s",s);
    return 0;
}
/*
5
11111 111111111 11 1111111111111111111111111 111
*/