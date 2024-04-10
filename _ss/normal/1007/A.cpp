#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define all(vr) vr.begin(),vr.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
const int N=1e5+10;
int a[N],n;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int j=n,res=0;
    for (int i=n;i>0 && j>0;i--)
    {
        while (a[j]>=a[i]) j--;
        if (j>0) res++;
        j--;
    }
    cout<<res;
    return 0;
}