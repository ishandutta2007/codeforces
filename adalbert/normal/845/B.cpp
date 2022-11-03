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
    string st;
    cin>>st;
    int ans=1e9;
    for (int i=0;i<=999;i++)
        for (int j=0;j<=999;j++)
        {
            int now=0;
            if (i/100!=st[0]-'0') now++;
            if (i/10%10!=st[1]-'0') now++;
            if (i%10!=st[2]-'0') now++;
            if (j/100!=st[3]-'0') now++;
            if (j/10%10!=st[4]-'0') now++;
            if (j%10!=st[5]-'0') now++;
            if (i/100+i/10%10+i%10 == j/100+j/10%10+j%10)
                ans=min(ans,now);
        }
    cout<<ans;
}