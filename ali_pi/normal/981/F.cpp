#include<bits/stdc++.h>

#define maxn 800100

using namespace std;

long long a[maxn],b[maxn],n,L;
int t[maxn],u[maxn];

bool query(long long x)
{
    int f=0;
    while(b[f]<=x)f++;
    int l=0,r=0;
    for(int i=f;i<f+n*2;i++)
    {
        while(b[i]-x>a[l])l++;
        t[i]=l;
        while(b[i]+x>=a[r])r++;
        u[i]=r-1;
    }
    int mn=maxn;
    for(int i=f;i<f+n*2;i++)
    {
        mn=min(mn,i-t[i]);
        if(i-u[i]>mn)return 0;
    }
    return 1;
}

long long bs(long long l,long long r)
{
    if(l==r)return l;
    long long m=(l+r)/2;
    if(query(m))return bs(l,m);
    return bs(m+1,r);
}

int main()
{
    cin>>n>>L;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    for(int i=0;i<n;i++)
        a[i+n]=a[i]+L;
    for(int i=0;i<n;i++)
        b[i+n]=b[i]+L;
    for(int i=0;i<n;i++)
        a[i+n*2]=a[i]+L*2;
    for(int i=0;i<n;i++)
        b[i+n*2]=b[i]+L*2;
    for(int i=0;i<n;i++)
        a[i+n*3]=a[i]+L*3;
    cout<<bs(0,L/2)<<endl;

}