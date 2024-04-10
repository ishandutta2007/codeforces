#include <bits/stdc++.h>
#define p_b push_back
//#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
string s;
ll tt[10000000];
ll j,m,kl,stn,c[1000000],i,n,x,a[1000000],b[1000000],c1,sc,sc1,ans=1e18,su;
int main() {
    ll l1,r1;
    // set < ll > :: iterator kek=s.begin;
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    c1=n-1;
     for(i=1;i<=n;i++)
        {
            while(sc+su>m)
            {
                sc--;
                s+=")";
            }
            s+="(";
            su+=sc;
            sc++;
        }
        if(su!=m)
        {
            cout << "Impossible" << endl;
            return 0;
        }
        while(sc>0)
        {
            s+=")";
            sc--;
        }
        cout << s << endl;
    return 0;
}