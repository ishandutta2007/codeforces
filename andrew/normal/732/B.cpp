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
ll k,x,c,sc,n,m,i,j,a[10000],b[100000],a1,b1,c1;
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
     cin >> n >> k;
     for(i=0;i<n;i++)cin >> a[i];
     for(i=1;i<n;i++)if(a[i]+a[i-1]<k)m+=(k-a[i]-a[i-1]),a[i]+=k-(a[i]+a[i-1]);
     cout << m << endl;
     for(i=0;i<n;i++)cout << a[i] << " ";
     cout << endl;

    return 0;
}