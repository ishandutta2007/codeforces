#include <bits/stdc++.h>
#define p_b push_back
//#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
ll binpow(ll a,ll n)
{
    ll res=1;
    while(n)
    {
        if(n%2)res*=a;
        a*=a;
        n/=2;
    }
    return res;
}
template <typename T>
T sqr(T x)
{
    return x*x;
}
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
const ll shl=1;
const ll MAXN=1123456;
vector <pll> v[MAXN];
set <pll> st;
string s;
map < string , ll > mp;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
ll l,r;
   cin >> s1 >> s2;
   sort(s1.begin(),s1.end());
   reverse(s1.begin(),s1.end());
   if(s1.size()<s2.size())vout(s1);
    while(s1.size()>s2.size()){
        k++;
        int kek=s1.find('0');
        s1.erase(kek,1);
    }
   //if(s1<=s2)vout(s1);
    s3=s1;
    //cout << s3 << endl;
    sort(s3.begin(),s3.end());
    while(s3.size()){
        ll nn=s3.size();
        for(i=nn-1;i>=0;i--){
                char cc=s3[i];
        s3.erase(i,1);
            s1=s+cc+s3;
            if(s1<=s2){
                s+=cc;
                break;
            }
            string sse;
            sse+=cc;
            s3.insert(i,sse);
        }
    }
    for(i=0;i<k;i++)cout << 0;
    cout << s << endl;
    return 0;
}