#include <bits/stdc++.h>
#define ll int
#define endl "\n"
#define fi first
#define se second
using namespace std;
ll a[10][10],c[5][5],n,m,i,j,k,c1;
int main() {

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    for(i=1;i<5;i++)for(j=1;j<5;j++)cin >> a[i][j];
    for(i=1;i<5;i++)
    {
        if(a[i][4]==1 and(a[i][1]==1 or a[i][2]==1 or a[i][3]==1))
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    c[1][1]=4; c[1][2]=3; c[1][3]=2;
    c[2][1]=1; c[2][2]=4; c[2][3]=3;
    c[3][1]=2; c[3][2]=1; c[3][3]=4;
    c[4][1]=3; c[4][2]=2; c[4][3]=1;
    ll fl=0;
    for(i=1;i<5;i++)for(j=1;j<4;j++)if(a[i][j]==1 and (a[c[i][j]][4]))fl=1;
    if(fl==1)cout << "YES"; else cout << "NO";
    cout << endl;
    return 0;
}