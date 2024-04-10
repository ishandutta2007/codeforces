#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=60;
LL cnt[V][4][4];
LL inner[V][4];
int st[V],ed[V];
int K,x,n,m;
char s1[120],s2[120];
int main()
{
    memset(cnt,0,sizeof(cnt));
    memset(inner,0,sizeof(inner));
    inner[1][1]=1;
    inner[2][2]=1;
    st[1]=ed[1]=1;
    st[2]=ed[2]=2;
    for(int i=3;i<=50;i++)
    {
        cnt[i][1][1]=cnt[i-1][1][1]+cnt[i-2][1][1];
        cnt[i][2][2]=cnt[i-1][2][2]+cnt[i-2][2][2];
        cnt[i][1][2]=cnt[i-1][1][2]+cnt[i-2][1][2];
        cnt[i][2][1]=cnt[i-1][2][1]+cnt[i-2][2][1];
        st[i]=st[i-2];ed[i]=ed[i-1];
        cnt[i][ed[i-2]][st[i-1]]++;
        inner[i][1]=inner[i-1][1]+inner[i-2][1];
        inner[i][2]=inner[i-1][2]+inner[i-2][2];
        //cout << i << " : " <<cnt[i][1][1] << " " <<cnt[i][1][2] << " "<<cnt[i][2][1]<<" "<<cnt[i][2][2]<<endl;
    }
    while(~scanf("%d%d%d%d",&K,&x,&n,&m))
    {
        bool find=false;
        for(int i=0;i<n&&!find;i++)
        for(int j=0;j<m&&!find;j++)
        for(int k=0;(k<(1<<4))&&!find;k++)
        {
            LL tmp=0;
            tmp+=inner[K][1]*i+inner[K][2]*j;
            if((k&1)&&(k&2))tmp+=cnt[K][1][1];
            if((k&4)&&(k&2))tmp+=cnt[K][1][2];
            if((k&1)&&(k&8))tmp+=cnt[K][2][1];
            if((k&4)&&(k&8))tmp+=cnt[K][2][2];
            if(tmp==x)
            {
                int ln=n,lm=m;
                if(k&1)ln--;
                if(k&2)ln--;
                if(k&4)lm--;
                if(k&8)lm--;
                if(ln>=i*2&&lm>=j*2)
                {
                    int st;
                    st=0;
                    if(k&1)st=1,s1[0]='C';
                    for(int ii=st;ii<st+i*2;ii+=2)
                    s1[ii]='A',s1[ii+1]='C';
                    for(int ii=st+i*2;ii<n;ii++)
                    s1[ii]='B';
                    if(k&2)s1[n-1]='A';
                    st=0;
                    if(k&4)st=1,s2[0]='C';
                    for(int ii=st;ii<st+j*2;ii+=2)
                    s2[ii]='A',s2[ii+1]='C';
                    for(int ii=st+j*2;ii<m;ii++)
                    s2[ii]='B';
                    if(k&8)s2[m-1]='A';
                    s1[n]=s2[m]=0;
                    puts(s1);
                    puts(s2);
                    find=true;break;
                }
            }
        }
        if(!find)puts("Happy new year!");
    }
}