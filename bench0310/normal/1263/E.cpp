#include <bits/stdc++.h>

using namespace std;

const int N=1000005;
int tmin[4*N];
int tmax[4*N];
int lazy[4*N];

void push(int idx)
{
    tmin[2*idx]+=lazy[idx];
    tmin[2*idx+1]+=lazy[idx];
    tmax[2*idx]+=lazy[idx];
    tmax[2*idx+1]+=lazy[idx];
    lazy[2*idx]+=lazy[idx];
    lazy[2*idx+1]+=lazy[idx];
    lazy[idx]=0;
}

void update(int idx,int l,int r,int ql,int qr,int val)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        tmin[idx]+=val;
        tmax[idx]+=val;
        lazy[idx]+=val;
    }
    else
    {
        push(idx);
        int m=(l+r)/2;
        update(2*idx,l,m,ql,min(qr,m),val);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,val);
        tmin[idx]=min(tmin[2*idx],tmin[2*idx+1]);
        tmax[idx]=max(tmax[2*idx],tmax[2*idx+1]);
    }
}

int query(int idx,int l,int r,int ql,int qr,int t)
{
    if(ql>qr)
    {
        if(t==0) return N;
        else return 0;
    }
    if(l==ql&&r==qr)
    {
        if(t==0) return tmin[idx];
        else return tmax[idx];
    }
    push(idx);
    int m=(l+r)/2;
    int a=query(2*idx,l,m,ql,min(qr,m),t);
    int b=query(2*idx+1,m+1,r,max(ql,m+1),qr,t);
    if(t==0) return min(a,b);
    else return max(a,b);
}

int main()
{
    int n;
    scanf("%d",&n);
    char s[n+1];
    scanf("%s",s);
    vector<char> v(N,' ');
    int idx=1;
    for(int i=0;i<n;i++)
    {
        char c=s[i];
        if(c=='L') idx=max(1,idx-1);
        else if(c=='R') idx++;
        else
        {
            if(v[idx]=='(') update(1,1,n,idx,n,-1);
            if(v[idx]==')') update(1,1,n,idx,n,1);
            v[idx]=c;
            if(c=='(') update(1,1,n,idx,n,1);
            if(c==')') update(1,1,n,idx,n,-1);
        }
        if(query(1,1,n,1,n,0)>=0&&query(1,1,n,n,n,0)==0) printf("%d ",query(1,1,n,1,n,1));
        else printf("-1 ");
    }
    printf("\n");
    return 0;
}