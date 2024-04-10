#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define double long double

const int inf = 2e12 + 42;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    vector<int> poses = {-1};
    for(int i = 0; i < n; i++)
        if(s[i] == '1')
            poses.push_back(i);
    poses.push_back(n);
    int sum = 0;
    for(int i = 1; i < poses.size(); i++)
        sum += (poses[i] - poses[i - 1] - 1) / b;
    cout << sum - a + 1 << endl;
    int cnt = sum - a + 1;
    for(int i = 0; i + 1 < poses.size(); i++)
    {
        int j = poses[i];
        while(cnt && j + b < poses[i + 1])
        {
            cnt--;
            j += b;
            cout << j + 1 << ' ';
        }
    }
    return 0;
}