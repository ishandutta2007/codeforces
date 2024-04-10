#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int a, b, n, m;
string ans[N][N];

int32_t main()
{
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            string str;
            cin>>str;
            int cnt=str[0]-'0' + str[1]-'0';
            if(cnt==1)
                b++;
            if(cnt==2)
                a++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a)
            {
                ans[i][j]="11";
                a--;
            }  
            else if(b>=m-j+1)
            {
                if(i==1 || ans[i-1][j]=="11" || ans[i-1][j]=="10")
                    ans[i][j]="01";
                else
                    ans[i][j]="10";
                b--;
            }
            else
            {
                ans[i][j]="00";
            }
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}