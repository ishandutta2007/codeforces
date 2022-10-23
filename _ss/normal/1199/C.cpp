#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=4e5+100;
int a[maxn],n,I,s[maxn],b[maxn];
void read()
{
    cin>>n>>I;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
}

void compress()
{
    int sl=1,m=0;
    for (int i=1;i<n;i++)
        if (a[i]==a[i+1]) sl++;
        else
        {
            m++;
            b[m]=sl;
            sl=1;
        }
    m++;
    b[m]=sl;
    n=m;
}

void process()
{
    int k=(I*8)/n;
    compress();
    if (k>20) k=1<<20; else k=1<<k;
    if (k>n) k=n;
    for (int i=1;i<=n;i++) s[i]=s[i-1]+b[i];
    int ans=1e9;
    for (int i=1;i<=n-k+1;i++) ans=min(ans,s[n]-(s[i+k-1]-s[i-1]));
    cout<<ans;
}

int main()
{
    read();
    process();
    return 0;
}