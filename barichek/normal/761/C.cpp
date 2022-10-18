#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
///#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

bool ok(char a)
{
    return a=='#'||a=='*'||a=='&';
}

bool kaka(char a)
{
    return a>='a'&&a<='z';
}

bool is_num(char a)
{
    return a>='0'&&a<='9';
}

void minimize(int &a,int b)
{
    if (a>b) a=b;
}

int dp[ar][2][2][2];
string a[ar];

main()
{
    for (int i=0;i<ar;i++)
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++)
                for (int p=0;p<2;p++)
                    dp[i][j][k][p]=1e7;
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    dp[0][0][0][0]=0;
    for (int i=0;i<n;i++)
    {
        int best_small=1e7;
        int best_ok=1e7;
        int best_num=1e7;
        for (int j=0;j<m;j++)
            if (ok(a[i+1][j]))
                minimize(best_ok,min(j,m-j));
            elif (kaka(a[i+1][j]))
                minimize(best_small,min(j,m-j));
            elif (is_num(a[i+1][j]))
                minimize(best_num,min(j,m-j));
        cerr<<i<<" :: "<<best_ok<<" "<<best_small<<" "<<best_num<<"\n";
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++)
                for (int p=0;p<2;p++)
                    for (int j1=j;j1<2;j1++)
                        for (int k1=k;k1<2;k1++)
                            for (int p1=p;p1<2;p1++)
                                if (int(j1!=j)+int(k1!=k)+int(p1!=p)<2)
                                    //cerr<<"to "<<i+1<<" "<<j1<<" "<<k1<<" "<<p1<<" from ::: ",
                                    //cerr<<int(dp[i][j][k][p]+
                                      //       ((j1!=j)*best_ok)
                                        //     +((k1!=k)*best_small)
                                          //   +((p1!=p)*best_num))<<"\n",
                                    minimize(dp[i+1][j1][k1][p1],int(dp[i][j][k][p]+
                                             ((j1!=j)*best_ok)
                                             +((k1!=k)*best_small)
                                             +((p1!=p)*best_num)));
    }
    cerr<<"!!!! :: "<<dp[1][1][0][0]<<"\n";
    cout<<dp[n][1][1][1];
}