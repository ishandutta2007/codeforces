#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fir first
#define sec second
#define pb push_back
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define y1 drfijortjubo
using namespace std;
typedef double ld;
typedef long long ll;
const int arr=2e5+10;
int n,m;

string st[600];

bool check1()
{
    int s1=1;
    int s2=n/3+1;
    int s3=2*n/3+1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<m;j++)
        if (st[i][j]!=st[i][j-1]) return(0);
    if (st[s1][0]==st[s2][0]) return(0);
    if (st[s1][0]==st[s3][0]) return(0);
    if (st[s3][0]==st[s2][0]) return(0);
    for (int i=s1+1;i<s2;i++)
        if (st[i][0]!=st[i-1][0]) return(0);
    for (int i=s2+1;i<s3;i++)
        if (st[i][0]!=st[i-1][0]) return(0);
    for (int i=s3+1;i<=n;i++)
        if (st[i][0]!=st[i-1][0]) return(0);
    return(1);
}

bool check2()
{
    int s1=0;
    int s2=m/3;
    int s3=2*m/3;
    for (int i=2;i<=n;i++)
        for (int j=0;j<m;j++)
        if (st[i][j]!=st[i-1][j]) return(0);
    if (st[1][s1]==st[1][s2]) return(0);
    if (st[1][s1]==st[1][s3]) return(0);
    if (st[1][s3]==st[1][s2]) return(0);
    for (int i=s1+1;i<s2;i++)
        if (st[1][i]!=st[1][i-1]) return(0);
    for (int i=s2+1;i<s3;i++)
        if (st[1][i]!=st[1][i-1]) return(0);
    for (int i=s3+1;i<m;i++)
        if (st[1][i]!=st[1][i-1]) return(0);
    return(1);
}

signed main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>st[i];
    if (n%3==0)
        if (check1())
        {
            cout<<"YES";
            return(0);
        }
    if (m%3==0)
        if (check2())
        {
            cout<<"YES";
            return(0);
        }
    cout<<"NO";
}