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
set <ll> s,sv;
ll p[1000001],i,j,n,m,m1,k,sc,dp,x,a[100000],b[100000],a1,b1,c1,ans;
int main() {

    // set < ll > :: iterator kek=s.begin;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i=0;i<n;i++)
    {
        ans=max(ans,m+m1);
        char cc;
        cin >> cc >> x;
        if(cc=='+')
        {
            a[x]=1;
            m++;
            m1=0;
        }
        if(cc=='-')
        {
            if(a[x]==0)
            {
                ans++;
            }else
            {
                a[x]=0;
                m--;
            }
        }
    }
    cout << max(ans,m) << endl;
    return 0;
}