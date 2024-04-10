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

    string st;
    cin>>st;
    int u=0,d=0,l=0,r=0;

    for (int i=0;i<st.size();i++)
        if (st[i]=='U')
        u++; else
        if (st[i]=='D')
        d++; else
        if (st[i]=='L')
        l++; else
        if (st[i]=='R')
        r++;

    cout<<n-abs(u-d)-abs(r-l);

}