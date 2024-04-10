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
        string s;
        cin >> s;
        vector<int> c(2,0);
        for(char a:s) c[a-'0']++;
        if(min(c[0],c[1])&1) cout << "DA\n";
        else cout << "NET\n";
    }
    return 0;
}