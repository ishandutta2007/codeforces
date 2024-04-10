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
        vector<bool> vis(n,0);
        int sum=0;
        int res=0;
        int idx=n-1;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==1) continue;
            if(s[i]=='(') sum++;
            else sum--;
            if(sum==-1)
            {
                res++;
                while(s[idx]==')') idx--;
                vis[idx--]=1;
                sum=0;
            }
        }
        cout << res << "\n";
    }
    return 0;
}