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
void rec(char x)
{
    ll i;
    stn++;
    s1[stn-1]=x;
    if(stn==6)
    {
        sc=0;
        ll x1=s1[0]-'0'+s1[1]-'0'+s1[2]-'0';
        ll x2=s1[3]-'0'+s1[4]-'0'+s1[5]-'0';
        if(x1==x2)
        {
            for(i=0;i<6;i++)if(s[i]!=s1[i])sc++;
            mx=min(mx,sc);
        }
        stn--;
        return;
    }
    for(char cc='0';cc<='9';cc++)rec(cc);
    stn--;
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    mx=1e18;
    s1="000000";
    cin >> s;
    for(char cc='0';cc<='9';cc++)rec(cc);
    cout << mx << endl;
    return 0;
}