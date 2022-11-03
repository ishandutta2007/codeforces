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
typedef double ld;
const int arr=5e5;

int a[arr];

signed main()
{
    int n;
    cin>>n;
    map<int,int> mp;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        mp[a]++;
    }
    int ans=0;
    for (auto i:mp)
        ans=max(ans,i.sec);
    cout<<ans;
}