#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,x,y;
        cin >> n >> m >> x >> y;
        int res=0;
        for(int o=0;o<n;o++)
        {
            string s;
            cin >> s;
            s=s+'*';
            int cnt=0;
            for(int i=0;i<=m;i++)
            {
                if(s[i]=='.') cnt++;
                else
                {
                    res+=(cnt/2)*min(2*x,y)+(cnt&1)*x;
                    cnt=0;
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}