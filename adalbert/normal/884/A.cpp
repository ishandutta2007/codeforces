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
const int arr=2e5;

signed main()
{
    int n,t;
    cin>>n>>t;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        t-=86400-a;
        if (t<=0)
        {
            cout<<i;
            return(0);
        }
    }


}

/*
!!! https://pastebin.com/jHpxMZq3
*/