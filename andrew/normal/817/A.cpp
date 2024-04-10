#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
using namespace std;
vector <ll> tt[1000];
string s,s1;
ll dp[10];
ll n,m,i,j,k,sc,a[10000],b[10000];
int main() {

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll y1,y2,x1,x2,y,x;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x >> y;
    if(abs(x2-x1)%x!=0 or abs(y2-y1)%y!=0)
    {
        cout << "NO" << endl;
        return 0;
    }
    x1=abs(x1-x2);
    y1=abs(y1-y2);
    x1=x1/x;
    y1/=y;
    //cout << x1 << " " << y1 << endl;
    ll ans;
    ans=abs(x1-y1);
    if(ans%2==0)cout << "YES"; else cout << "NO";
    cout << endl;
    return 0;
}