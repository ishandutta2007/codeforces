#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 1;
    deque<pair<int, char>> vec;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] != s[i - 1])
        {
            vec.emplace_back(cnt, s[i - 1]);
            cnt = 0;
        }
        cnt++;
    }
    vec.emplace_back(cnt, s.back());
    if (vec.size() % 2 == 0)
        return cout << 0, 0;

    while (vec.size() > 1)
    {
        auto [a, b] = vec.front();
        auto [c, d] = vec.back();
        if (a + c < 3 || b != d)
            return cout << 0, 0;
        vec.pop_front();
        vec.pop_back();
    }
    if (vec.front().first >= 2)
        cout << vec.front().first + 1;
    else
        cout << 0;
}