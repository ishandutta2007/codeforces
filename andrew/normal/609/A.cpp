#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
vector <ll> tt[1000];
set <ll> ss;
map < string , ll > mp;
string s,s1;
char cc;
ll c,sc,n,m,i,j,a[10000],b[100000],a1,b1,c1;
int main() {

    // set < ll > :: iterator kek=s.begin;
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    reverse(a,a+n);
    for(i=0;i<n;i++)
    {
        m-=a[i];
        if(m<=0)
        {
            cout << i+1 << endl;
            return 0;
        }
    }

    return 0;
}