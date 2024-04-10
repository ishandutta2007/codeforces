#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+10;
int n,a[maxn],x,y;
int main()
{
    cin>>n>>x>>y;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
    {
        int check=1;
        for (int j=max(1,i-x);j<i;j++) if (a[j]<a[i]) check=0;
        for (int j=i+1;j<=min(n,i+y);j++) if (a[j]<a[i]) check=0;
        if (check)
        {
            cout<<i;
            break;
        }
    }
    return 0;
}