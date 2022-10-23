#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=2e3+10;
int a[maxn][maxn],b[maxn],n,m;
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        char ch=getchar();
        for (int j=1;j<=m;j++)
        {
            ch=getchar();
            a[i][j]=ch-'0';
            b[j]+=ch-'0';
        }
    }
    for (int i=1;i<=n;i++)
    {
        int check=1;
        for (int j=1;j<=m;j++)
            if (a[i][j]==b[j]) check=0;
        if (check)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}