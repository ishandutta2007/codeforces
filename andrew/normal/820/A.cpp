#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
using namespace std;
vector <ll> tt[1000];
set <ll> ss;
map < string , ll > mp;
string s,s1;
char c,cc;
ll n,m,i,j,a[1000000],b,v[1000000],a1,sc,l,sk,b1,c1;
int main() {
    ll v1,v0;
    // set < ll > :: iterator kek=s.begin;
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> v0 >> v1 >> b >> l;

    sk=v0;
    ll x=l;
    while(1)
    {
        sc++;
        x-=l;
        x+=min(sk,v1);
        if(x>=n)break;
        sk+=b;
    }
    cout << sc << endl;
    return 0;
}