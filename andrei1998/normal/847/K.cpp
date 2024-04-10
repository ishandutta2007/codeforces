#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

map <pair <string, string>, int> Map;

pair <string, string> mp(string a, string b) {
    if (a < b)
        swap(a, b);
    return {a, b};
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, a, b, k, f;
    cin >> n >> a >> b >> k >> f;

    string last = "--!";

    int ans = 0;
    for (int i = 1; i <= n; ++ i) {
        string x;
        string y;
        cin >> x >> y;
        if (x == last)
            Map[mp(x, y)] += b, ans += b;
        else
            Map[mp(x, y)] += a, ans += a;
        last = y;
    }

    vector <int> v;
    for (auto it: Map)
        v.push_back(it.second);

    sort(v.begin(), v.end(), greater <int>());

    for (int i = 0; i < v.size() && i < k; ++ i)
        if (v[i] > f)
            ans += f - v[i];
    cout << ans << '\n';
    return 0;
}