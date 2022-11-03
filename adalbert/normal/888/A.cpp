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

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    int ans=0;

    for (int i=2;i<n;i++)
    {
        bool ch=0;
        if (a[i]>a[i-1] && a[i]>a[i+1])
            ch=1;
        if (a[i]<a[i-1] && a[i]<a[i+1])
            ch=1;
        ans+=ch;
    }
    cout<<ans;
}