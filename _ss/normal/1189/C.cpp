#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+10;
int n,a[maxn];

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    int q;
    cin>>q;
    int l,r;
    for (int i=1;i<=q;i++)
    {
        scanf("%d %d",&l,&r);
        printf("%d \n",(a[r]-a[l-1])/10);
    }
    return 0;
}