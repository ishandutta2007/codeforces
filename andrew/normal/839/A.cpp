#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
const ll shl=1;
vector <ll> tt[1000];
set <ll> ss;
map < string , ll > mp;
string s,s1;
char cc;
ll c,sc,n,m,i,j,a[1000000],b[1000000],a1,b1,c1,ans,x,k;
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> k;
    for(i=0;i<n;i++)
    {
        cin >> x;
        x+=c;
        c=0;
        sc+=min(x,8ll);
        if(sc>=k)
        {
            cout << i+1 << endl;
            return 0;
        }
        if(x>8)x-=8;else x=0;
        c+=x;
    }
    cout << -1 << endl;
    return 0;
}