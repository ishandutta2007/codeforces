#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 42, sigma = 26;
const int mod = 1e9 + 7;

int dp[sigma];

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int m = s.size();
    int sum = 1;
    int lst[k];
    memset(lst, 0, sizeof(lst));
    for(int i = 0; i < m; i++)
    {
        int t = (sum - dp[s[i] - 'a'] + mod);
        if(t > mod)
            t -= mod;
        dp[s[i] - 'a'] = sum;
        sum += t;
        if(sum > mod)
            sum -= mod;
        lst[s[i] - 'a'] = i + 1;
    }
    deque<int> p(k);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int a, int b){return lst[a] < lst[b];});
    for(int i = m; i < n + m; i++)
    {
        int t = sum - dp[p.front()] + mod;
        if(t > mod)
            t -= mod;
        dp[p.front()] = sum;
        sum += t;
        if(sum > mod)
            sum -= mod;
        p.push_back(p.front());
        p.pop_front();
    }
    cout << sum << "\n";
}