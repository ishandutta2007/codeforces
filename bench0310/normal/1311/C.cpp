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
        int n,m;
        cin >> n >> m;
        vector<int> v(n+1,0);
        string s;
        cin >> s;
        s="0"+s;
        int sum=m+1;
        while(m--)
        {
            int x;
            cin >> x;
            v[x+1]--;
        }
        vector<int> res(26,0);
        for(int i=1;i<=n;i++)
        {
            sum+=v[i];
            res[s[i]-'a']+=sum;
        }
        for(int i=0;i<26;i++) cout << res[i] << " \n"[i==25];
    }
    return 0;
}