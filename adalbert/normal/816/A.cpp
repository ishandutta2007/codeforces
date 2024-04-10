#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define pb push_back
typedef long long ll;
typedef long double ld;
const int arr=300000+10;

bool check(int a, int b)
{
    return (a%10==b/10 && a/10==b%10) ;
}

signed main()
{
    string st;
    cin>>st;
    int h=(st[0]-'0')*10+st[1]-'0';
    int m=(st[3]-'0')*10+st[4]-'0';
    int ans=0;
    while (!check(h,m))
    {
        m++;
        ans++;
        if (m==60)
        {
            m=0;
            h++;
        }
        h%=24;
    }
    cout<<ans;
}