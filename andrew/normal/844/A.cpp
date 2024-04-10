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
const ll maxn=1000000;
vector <ll> tt[1000];
set <ll> ss;
map < string , ll > mp;
string s,s1;
char cc;
ll k,c,sc,n,m,i,j,a[10000],b[100000],a1,b1,c1,ans,x;
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> s;
    cin >> k;
    n=s.size();
    if(k>n)
    {
        cout << "impossible" << endl;
        return 0;
    }
    for(i=0;i<n;i++)

    {
        x=s[i]-'a';
        a[x]=1;
    }
    for(i=0;i<26;i++)sc+=a[i];
    cout << max(0ll,k-sc) << endl;
    return 0;
}