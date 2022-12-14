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
ll sc,n,m,i,j,v[1000000],st[1000000],b[1000000],dd,stn,a1,dp,b1,c1,x;
int main() {

    // set < ll > :: iterator kek=s.begin;
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    dp=1;
    for(i=0;i<n*2;i++)
    {
       cin >> s;
       while(b[st[stn]]==-1)stn--;
       if(s=="add")
       {
           cin >> x;
           stn++;
           st[stn]=x;
           v[x]=dp;
       }
       if(s=="remove")
       {
           dd++;
           if(stn==0)continue;
           if(st[stn]==dd){stn--;continue;};
           //cout << dd << endl;
           stn=0;
           sc++;

       }
    }
    cout << sc << endl;

    return 0;
}