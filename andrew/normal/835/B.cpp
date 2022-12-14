#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
#define endl "\n"
#define pll pair<ll,ll>
ll a[10000],b[10000],c,a1,b1,c1,n,m,x,i,j,sc,ans,k;
string s;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    cin >> s;
    n=s.size();
    for(i=0;i<n;i++)
    {
        ll kk=s[i]-'0';
        sc+=kk;
    }
    sort(s.begin(),s.end());
    for(i=0;i<n;i++)
    {
        if(sc>=k)break;
       ans++;
       ll kk=s[i]-'0';
       sc+=(9-kk);
    }
    cout << ans << endl;
return 0;
}