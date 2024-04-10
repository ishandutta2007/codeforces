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
ll ans,c,sc,n,m,i,j,a[10000],b[100000],a1,b1,c1,x;
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> a1 >> b1;
    for(i=0;i<n;i++)
    {
        cin >> x;
        //cout << a1 << " " << b1 << " " << c1 << endl;
        if(x==1)
        {
            if(a1==0 and b1==0 and c1==0)ans++;else
            if(a1!=0)a1--;else
            if(b1>0)
            {
               b1--;
               c1++;
            }else
            {
                c1--;
            }
        }
        if(x==2)
        {
            if(b1==0)ans+=2;else b1--;
        }
    }
    cout << ans << endl;
    return 0;
}