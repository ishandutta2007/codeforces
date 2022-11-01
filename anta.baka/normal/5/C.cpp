#include <bits/stdc++.h>

using namespace std;

string s;
int n;
int lopt, copt;
stack<int> st;
int par[1000000];
int dp[1000000];

int main()
{
    ios::sync_with_stdio(0);
    memset(par, -1, sizeof par);
    cin >> s;
    n = s.size();
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(') st.push(i);
        else if(!st.empty())
        {
            int t = st.top();
            st.pop();
            par[i] = t;
            par[t] = i;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(par[i] == -1 || par[i] > i) continue;
        dp[i] = i - par[i] + 1;
        if(par[i]) dp[i] += dp[par[i] - 1];
        lopt = max(lopt, dp[i]);
    }
    if(!lopt) return cout << "0 1", 0;
    for(int i = 0; i < n; i++) if(dp[i] == lopt) copt++;
    cout << lopt << ' ' << copt;
}