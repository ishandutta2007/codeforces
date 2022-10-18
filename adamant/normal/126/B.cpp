#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int cnt[n], p[n];
    memset(cnt, 0, sizeof(cnt));
    p[0] = 0;
    for(int i = 1; i < n; i++)
    {
        p[i] = p[i - 1];
        while(p[i] && s[i] != s[p[i]]) p[i] = p[p[i] - 1];
        if(s[i] == s[p[i]]) p[i]++;
        cnt[p[i]]++;
    }
    for(int i = n - 1; i; i--)
        cnt[p[i - 1]] += cnt[i];
    string ans = "Just a legend";
    for(int j = p[n - 1]; j; j = p[j - 1])
        if(cnt[j] > 1)
        {
            ans = s.substr(0, j);
            break;
        }
    cout << ans;
}