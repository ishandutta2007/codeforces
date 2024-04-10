#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 4005;
char used[MAXN];
long long v[MAXN], d[MAXN], p[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i] >> d[i] >> p[i];
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(p[i] < 0)
            continue;
        ans.push_back(i);
        long long x = v[i];
        for(int j = i + 1; j < n && x > 0; j++)
            if(p[j] >= 0) {
                p[j] -= x;
                x--;
            }
        x = 0;
        for(int j = i + 1; j < n; j++) {
            if(used[j])
                continue;
            p[j] -= x;
            if(p[j] < 0) {
                used[j] = true;
                x += d[j];
            }
        }
    }
    cout << ans.size() << '\n';
    for(size_t i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << ' ';
    cout << '\n';
    return 0;
}