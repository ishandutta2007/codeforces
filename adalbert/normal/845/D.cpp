#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pii;
typedef vector <pii> vii;
const ld pi = acos(-1);
const int arr = 4*1e5+100;
const ll md = 1e9+7;
const ll base=31;
const int AaA = 'a'-'A';
ld eps=1e-7;
int a[arr];
signed main()
{
    int res=0;
    int n;
    cin>>n;
    vector<int> can,speed;
    can.pb(1);
    speed.pb(1e9);
    int now_speed=1e9;
    int ans=0;
    while (n--)
    {
        int t;
        cin>>t;
        if (t==1)
        {
            int now;
            cin>>now;
            while (speed.back()<now)
            {
                speed.pop_back();
                ans++;
            }
            now_speed=now;
        } else
        if (t==2)
        {
            while (!can.back())
            {
                can.pop_back();
                ans++;
            }
        } else
        if (t==3)
        {
            int now;
            cin>>now;
            if (now<now_speed) ans++; else
                speed.push_back(now);
        } else
        if (t==4)
        {
            can.pb(1);
        } else
        if (t==5)
        {
            while (speed.size()!=1)
                speed.pop_back();
        } else
        {
            can.pb(0);
        }
    }
    cout<<ans;
}