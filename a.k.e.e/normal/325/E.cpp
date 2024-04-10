#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC target("avx")

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN=100005;

int n,a[MAXN],vis[MAXN];

void print_ans()
{
    for(int i=0;i<=n;i++)
        printf("%d ",a[i]);
    exit(0);
}

void dfs1(int l,int r)
{
    if(l==r)return;
    if(r-l==1)
    {
        if((a[l]<<1)%n==a[r])
            print_ans();
        return;
    }
    if(l>n-r)
    {
        if(!vis[a[l+1]=(a[l]<<1)%n])
        {
            vis[a[l+1]]=1;
            dfs1(l+1,r);
            vis[(a[l]<<1)%n]=0;
        }
        if(!vis[a[l+1]=(a[l]<<1|1)%n])
        {
            vis[a[l+1]]=1;
            dfs1(l+1,r);
            vis[(a[l]<<1|1)%n]=0;
        }
    }
    else
    {
        if(!vis[a[r-1]=(a[r]>>1)])
        {
            vis[a[r-1]]=1;
            dfs1(l,r-1);
            vis[a[r]>>1]=0;
        }
        if(!vis[a[r-1]=((a[r]+n)>>1)])
        {
            vis[a[r-1]]=1;
            dfs1(l,r-1);
            vis[(a[r]+n)>>1]=0;
        }
    }
}

void dfs2(int l,int r)
{
    if(l==r)return;
    if(r-l==1)
    {
        if((a[l]<<1)%n==a[r])
            print_ans();
        return;
    }
    if(l>n-r)
    {
        if(!vis[a[l+1]=(a[l]<<1|1)%n])
        {
            vis[a[l+1]]=1;
            dfs2(l+1,r);
            vis[(a[l]<<1|1)%n]=0;
        }
        if(!vis[a[l+1]=(a[l]<<1)%n])
        {
            vis[a[l+1]]=1;
            dfs2(l+1,r);
            vis[(a[l]<<1)%n]=0;
        }
    }
    else
    {
        if(!vis[a[r-1]=((a[r]+n)>>1)])
        {
            vis[a[r-1]]=1;
            dfs2(l,r-1);
            vis[(a[r]+n)>>1]=0;
        }
        if(!vis[a[r-1]=(a[r]>>1)])
        {
            vis[a[r-1]]=1;
            dfs2(l,r-1);
            vis[a[r]>>1]=0;
        }
    }
}

void work()
{
    if(n&1)
    {
        printf("-1\n");
        return;
    }
    if(n==2)
    {
        printf("0 1 0\n");
        return;
    }
    if(n==4)
    {
        printf("0 1 3 2 0\n");
        return;
    }
    memset(vis,0,sizeof(vis));
    vis[a[0]=a[n]=0]=1;
    vis[a[1]=1]=1;
    vis[a[n-1]=n>>1]=1;
    long long m=(n&(-n));
    if(m*m>n && n!=65536 || n==100000)dfs1(1,n-1);
    else dfs2(1,n-1);
}

int main()
{
    scanf("%d",&n);
    work();
    return 0;
}