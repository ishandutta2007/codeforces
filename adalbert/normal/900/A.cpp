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
const int arr=2e5;

signed main()
{
    int n;
    cin>>n;

    int cnt1=0,cnt2=0;
    for (int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        if (x<0)
            cnt1++; else
            cnt2++;
    }

    if (cnt1<=1 || cnt2<=1)
        cout<<"Yes"; else
        cout<<"No";
}