#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define double long double

const int inf = 2e12 + 42;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    int a[n];
    int wrong = 0;
    int cnt[n];
    fill(cnt, cnt + n, 0);
    int mx = 0;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] == 0 && i + 1 != s)
            {wrong++; continue;}
        if(a[i] != 0 && i + 1 == s)
            {ans++; continue;}
        mx = max(mx, a[i]);
        cnt[a[i]]++;
    }
    ans += wrong;
    deque<int> rest;
    for(int i = 1; i <= mx; i++)
        if(cnt[i] == 0 && wrong > 0)
        {
            wrong--;
            cnt[i] = 1;
        }
        else if(cnt[i] == 0)
        {
            rest.push_back(i);
        }
    for(int i = mx; i >= 1; i--)
    {
        while(rest.size() && cnt[i])
        {
            ans++;
            cnt[rest.front()]++;
            cnt[i]--;
            rest.pop_front();
        }
        if(rest.empty())
            break;
        if(rest.back() == i)
            rest.pop_back();
    }
    cout << ans << endl;
    return 0;
}