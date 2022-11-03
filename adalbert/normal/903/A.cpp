#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define right dgfdogjreg
#define int ll
typedef long long ll;
typedef double ld;
const int arr=5e5;

int md=1e9+7;

int dp[400];


signed main()
{
    dp[0]=1;

    for (int i=0;i<=100;i++)
        dp[i+3]|=dp[i];
    for (int i=0;i<=100;i++)
        dp[i+7]|=dp[i];

    int n;
    cin>>n;
    while (n--)
    {
        int a;
        cin>>a;
        if (dp[a])
            cout<<"YES"<<'\n'; else
            cout<<"NO"<<'\n';
    }
}