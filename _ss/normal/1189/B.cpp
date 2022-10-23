#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+10;
int a[maxn],n,b[maxn];

bool cmp(int t1,int t2)
{
    return t1>t2;
}

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1,cmp);
    if (a[1]>=a[2]+a[3])
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    int t=n,k=1;
    for (int i=1;i<=n;i++)
    if (i&1)
    {
        b[k]=a[i];
        k++;
    }
    else
    {
        b[t]=a[i];
        t--;
    }
    for (int i=1;i<=n;i++) printf("%d ",b[i]);
    return 0;
}