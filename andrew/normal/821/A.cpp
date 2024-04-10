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
ll sc,n,m,i,j,a[1000][1000],b[1000][1000];
int main() {

ll i1,j1;
    // set < ll > :: iterator kek=s.begin;
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i=0;i<n;i++)for(j=0;j<n;j++)cin >> a[i][j];
    for(i=0;i<n;i++)for(j=0;j<n;j++)for(i1=0;i1<n;i1++)for(j1=0;j1<n;j1++)if(a[i1][j]+a[i][j1]==a[i][j])b[i][j]=1;
    for(i=0;i<n;i++)for(j=0;j<n;j++)if(a[i][j]==1)b[i][j]=1;
    for(i=0;i<n;i++)for(j=0;j<n;j++)if(b[i][j]==0)
    {
        //cout << i << " " << j << endl;
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}