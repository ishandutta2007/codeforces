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
        vector<bool> v(2,0);
        for(char c:s) v[c-'0']=1;
        if(v[0]==0||v[1]==0) cout << s << "\n";
        else
        {
            string res;
            for(char c:s)
            {
                if(res.empty()||res.back()!=c) res+=c;
                else
                {
                    res+=('0'+'1'-c);
                    res+=c;
                }
            }
            cout << res << "\n";
        }
    }
    return 0;
}