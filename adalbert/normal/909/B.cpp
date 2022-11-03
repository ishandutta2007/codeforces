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
typedef long long ll;
typedef double ld;
const int arr=2e5+1000;

int ans[500];

signed main()
{
    int n;
    cin>>n;
    ans[0]=0;
    ans[1]=1;
    for (int i=2;i<=n;i++)
        ans[i]=ans[i-2]+i;
    cout<<ans[n];
}