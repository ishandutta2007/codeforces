#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fir first
#define sec second
#define pii pair<int, int>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1 , 0};
const int mxN=301000;
const int mxM=2100000;
const ll MOD=1000000007;
const int INF=100000000;
char s[mxN];
int main()
{
    gibon
    int t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        int len=strlen(s);
        int ans=INF;
        for(int i=0;i<=9;i++)
        {
            for(int j=0;j<=9;j++)
            {
                int sum=0;
                int typ=0;
                int cur=0;
                while(cur<len)
                {
                    if(typ==0)
                    {
                        if(s[cur]-'0'==i)   typ=1;
                        else    sum++;
                    }
                    else
                    {
                        if(s[cur]-'0'==j)   typ=0;
                        else    sum++;
                    }
                    cur++;
                }
                if(typ==1 && sum!=len-1 && i!=j)  sum++;
                ans=min(ans, sum);
            }
        }
        cout << ans << '\n';
    }
}