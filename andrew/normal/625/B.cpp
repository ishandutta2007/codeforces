#include <bits/stdc++.h>
#define p_b push_back
//#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
vector <ll> tt[1000];
string s,s1;
ll value,net,p[1000000],i,j,n,m,k,sc,dp[1000000],x,a[100000],b[100000],a1,b1,c1,ans,mxj,val[1000000],next[1000000],mx;
int main() {
srand(time(0));
    // set < ll > :: iterator kek=s.begin;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> s1;
    n=s1.size();
    while(1)
    {
        int it=s.find(s1);
        if(it==-1)break;
        sc++;
        s.erase(0,it+n);
    }
    cout << sc << endl;
    return 0;
}