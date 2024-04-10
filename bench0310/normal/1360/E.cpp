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
        cin >> n;
        vector<string> s(n);
        for(int i=0;i<n;i++) cin >> s[i];
        bool ok=1;
        for(int o=0;o<n-1;o++) for(int i=0;i<n-1;i++) if(s[o][i]=='1') ok&=(s[o+1][i]=='1'||s[o][i+1]=='1');
        if(ok==1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}