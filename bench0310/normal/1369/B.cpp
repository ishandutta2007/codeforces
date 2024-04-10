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
        int n;
        string s;
        cin >> n >> s;
        string res;
        for(int i=0;i<n&&s[i]=='0';i++) res+="0";
        bool one=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1') one=1;
            if(s[i]=='0'&&one==1)
            {
                res+="0";
                break;
            }
        }
        for(int i=n-1;i>=0&&s[i]=='1';i--) res+="1";
        cout << res << "\n";
    }
    return 0;
}