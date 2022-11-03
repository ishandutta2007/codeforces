#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define right dgfdogjreg
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=5e5;

int a[arr],can[400];

signed main()
{
    int n,x,k;
    cin>>n>>x>>k;



    for (int i=1;i<=n;i++)
        cin>>a[i];

    a[n+1]=1e18;

    sort(a+1,a+1+n);

    int l=1;
    int r=1;

    int ans=0;

    for (int i=1;i<=n;i++)
    {
        int left=(a[i]-1)/x+k;
        left*=x;
        int right=left+x;
        left=max(left,a[i]);
      //  cout<<a[i]<<' '<<left<<' '<<right<<'\n';
        while (a[l]<left)
            l++;
        while (a[r]<right)
            r++;
       // cout<<l<<' '<<r<<'\n';
        ans+=r-l;
    }

    cout<<ans;
}

/*
1
0.1 0.2 0.3
1.0 0.5 0.3
1.0 0.0 0.2
*/