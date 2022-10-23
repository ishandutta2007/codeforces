#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+10;
int a[maxn],n,presum[maxn],k;

void read()
{
    cin>>n>>k;
    char c=getchar();
    for (int i=1;i<=n;i++) c=getchar(),a[i]=c-'0';
}

void process()
{
    int check=0,pre0=0,pre1=0,suf0=0,suf1=0;
    for (int i=1;i<=n;i++) presum[i]=presum[i-1]+a[i];
    for (int i=1;i<=n;i++)
        if (!a[i]) pre0++; else break;
    for (int i=1;i<=n;i++)
        if (a[i]) pre1++; else break;
    for (int i=n;i;i--)
        if (!a[i]) suf0++; else break;
    for (int i=n;i;i--)
        if (a[i]) suf1++; else break;
    if (pre0+suf0+k>=n) check=1;
    if (pre1+suf1+k>=n) check=1;
    if (check)
    {
        cout<<"tokitsukaze"; return;
    }
    for (int i=1;i<=n-k+1;i++)
    {
        int tmp=0;
        if (presum[i-1]) tmp+=(i-1+k-1)/k;
        if ((presum[n]-presum[i+k-1])) tmp+=(n-i-k+1+k-1)/k;
        if (tmp>1) check=1;
        tmp=0;
        if (presum[i-1]!=(i-1)) tmp+=(i-1)/k;
        if ((presum[n]-presum[i+k-1])!=(n-i-k+1)) tmp+=(n-i-k+1+k-1)/k;
        if (tmp>1) check=1;
    }
    if (check) cout<<"once again"; else cout<<"quailty";
}

int main()
{
    read();
    process();
    return 0;
}