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
ll ans,c,sc,n,m,i,j,a[10000],b[100000],a1,b1,c1;
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ll uk;
    cin >> uk;
    cin >> s;
    i=1;
    uk--;
    while(1)
    {
        if(uk<0)break;
        sc=0;
        while(s[uk]=='1' and uk>=0)uk--,sc++;
        //cout <<sc << endl;
        ans=ans+i*(sc);
        uk--;
        i*=10;
    }
    cout << ans << endl;
    return 0;
}