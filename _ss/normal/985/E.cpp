#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=5e5+10;
int n,a[maxn],d,k,p[maxn],s[maxn];

void read()
{
    cin>>n>>k>>d;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
}

void process()
{
    for (int i=1;i<=n;i++)
    {
        p[i]=max(p[i-1],i);
        while (p[i]+1<=n && a[p[i]+1]-a[i]<=d) p[i]++;
    }
    for (int i=n-k+1;i;i--)
    {
        s[i]=s[i+1];
        if (p[i]==n) s[i]++;
        else
        {
            if (p[i]-i+1<k) continue;
            if (s[i+k]-s[p[i]+2]>0) s[i]++;
        }
    }
    if (s[1]-s[2]>0) cout<<"YES"; else cout<<"NO";
}

int main()
{
    read();
    process();
    return 0;
}