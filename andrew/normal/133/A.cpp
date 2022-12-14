#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
vector <ll> tt[1000];
string s,s1;
ll p[1000000],i,j,n,m,k,sc,dp[1000000],x,a[100000],b[100000],a1,b1,c1,ans;
void fout(string s)
{
    cout << s << endl;
    fflush(stdout);
}
void vout(string s)
{
    cout << s << endl;
    exit(0);
}
template <typename T>
T sqr(T x)
{
    return x*x;
}
ll gcd(ll a,ll b)
{
    while(a>0 && b>0)a>b?a%=b:b%=a;
    return a+b;
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    char cc;
    s1="HQ9";
    while(cin >> cc)
    {
        int kek=s1.find(cc);
        if(kek>-1)vout("YES");
    }
    vout("NO");
    return 0;
}