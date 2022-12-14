#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
#define endl "\n"
#define pll pair<ll,ll>
string s,s1,s2,ss1,ss2,s3,s4;
ll a[10000],b[10000],c,a1,b1,c1,n,m,x,i,j,sc,ans,k;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);


    cin >> s >> s1;
s2="v<^>";
 cin >> n;
 n%=4;
ss1="<^>v";
ss2=">v<^";
if(n==0)
{
    cout << "undefined" << endl;
    return 0;
}
s3=s;
for(i=0;i<n;i++)
{
    int kek=s2.find(s3);
    s3=ss1[kek];
}
s4=s;
for(i=0;i<n;i++)
{
    int kek=s2.find(s4);
    //cout << s4 << "-" << ss2[kek] << "-" << kek << endl;
    s4=ss2[kek];
}
//cout << s3 << " " << s4 << endl;
if(s4==s3 and s3==s1)
{
    cout << "undefined" << endl;
}else
if(s4==s1)
{
    cout << "ccw" << endl;
}else cout << "cw" << endl;

return 0;
}