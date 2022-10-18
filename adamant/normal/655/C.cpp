#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> pos;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '0')
            pos.push_back(i);
    int ans = n;
    set<int> poses;
    for(int i = 0; i < k; i++)
        poses.insert(pos[i]);
    for(int i = k; i < pos.size(); i++)
    {
        poses.insert(pos[i]);
        if(i > k)
            poses.erase(pos[i - k - 1]);
        auto it = poses.lower_bound((*poses.begin() + *prev(poses.end())) / 2);
        ans = min(ans, max(*it - *poses.begin(), *prev(poses.end()) - *it));
        if(it == poses.begin())
            continue;
        it--;
        ans = min(ans, max(*it - *poses.begin(), *prev(poses.end()) - *it));
    }
    cout << ans << "\n";
}