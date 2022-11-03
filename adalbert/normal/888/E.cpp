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
const int arr=3e5;

int a[arr];

bool get(int u, int i)
{
    return((u&(1<<i))!=0);
}

signed main()
{
    int n,md;
    cin>>n>>md;

    for (int i=1;i<=n;i++)
        cin>>a[i];

    int mxl=(1<<(n/2));
    int mxr=(1<<(n-n/2));

    set<int> left,right;

    for (int i=0;i<mxl;i++)
    {
        int now=0;
        for (int j=0;j<n/2;j++)
        {
            if (get(i,j))
                now+=a[j+1];
            now%=md;
        }
        left.insert(now);
    }
    left.insert(0);

    for (int i=0;i<mxr;i++)
    {
        int now=0;
        for (int j=0;j<n-n/2;j++)
        {
            if (get(i,j))
                now+=a[n/2+j+1];
            now%=md;
        }
        right.insert(now);
    }
    right.insert(0);
    int ans=0;
    for (auto i:left)
    {
        int mx=*(--right.lower_bound(md-i));
       // cout<<i<<' '<<mx<<'\n';
        ans=max(ans,i+mx);
    }

    cout<<ans;
}