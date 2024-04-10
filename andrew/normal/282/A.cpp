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
ll ans,k,n;
string s;
int main() {

    // set < ll > :: iterator kek=s.begin;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n>0)
    {
        cin >> s;
        int k=s.find("+");
        if(k!=-1)ans++;else ans--;
       n--;
    }
    cout << ans << endl;
   return 0;
}