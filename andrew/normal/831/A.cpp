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
ll i1,c,sc,n,m,i,j,a[10000],b[100000],a1,b1,c1;
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=0;i<n;i++)
        for(j=i+1;j<=n+1;j++)
    {
        ll fl=0;
         for(i1=i+2;i1<j;i1++)if(a[i1]!=a[i1-1])fl=1;
         if(fl==1)continue;
         for(i1=1;i1<=i;i1++)if(a[i1]>=a[i1+1])fl=1;
         if(fl==1)continue;
         for(i1=j;i1<=n;i1++)if(a[i1]>=a[i1-1])fl=1;
         if(fl==1)continue;
         //cout << i << " " << j << endl;
         cout << "YES" << endl;
         return 0;
    }
    cout << "NO" << endl;
    return 0;
}