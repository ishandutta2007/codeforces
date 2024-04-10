#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1;
ld a[maxn];
ll b[maxn],n;
int main()
{
    cin>>n;
    ll s=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=(ll)(a[i]);
        s+=b[i];
    }
    for (int i=1;i<=n;i++)
    {
        if (s>0 && a[i]<0 && a[i]!=b[i])
        {
            s--;
            b[i]--;
        }
        if (s<0 && a[i]>0 && a[i]!=b[i])
        {
            s++;
            b[i]++;
        }
    }
    for (int i=1;i<=n;i++) cout<<b[i]<<endl;
    return 0;
}