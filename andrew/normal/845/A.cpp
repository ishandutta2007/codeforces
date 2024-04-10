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
string s,s1;
ll stn,mx,mp[1000000],i,j,n,m,k,sc,dp,x,a[100000],b[100000],a1,b1,c1,ans;
int main() {

    // set < ll > :: iterator kek=s.begin;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
   cin >> n;
   m=n*2;
   for(i=0;i<m;i++)cin >> a[i];
   sort(a,a+m);
   if(a[n-1]==a[n])cout << "NO";else cout << "YES";
   cout << endl;
    return 0;
}