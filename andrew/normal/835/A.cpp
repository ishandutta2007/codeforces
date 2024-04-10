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
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll a2,b2;
    ll ans1,ans2;
    cin >> n >> a1 >> a2 >> b1 >> b2;
    ans1=a1*n+b1*2;
    ans2=a2*n+b2*2;
    if(ans1==ans2)cout << "Friendship";else if(ans1<ans2)cout << "First";else cout << "Second";
    cout << endl;

return 0;
}