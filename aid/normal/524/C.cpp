#include <iostream>
#include <unordered_map>

using namespace std;

const int MAXN = 5005;
int a[MAXN];
unordered_map<int, int> mp;

void add(int x, int k) {
    if(mp.find(x) == mp.end()) {
        mp[x] = k;
        return;
    }
    mp[x] = min(mp[x], k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    mp[0] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 1; j <= k; j++)
            add(a[i] * j, j);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        int ans = k + 1;
        for(int j = 0; j < n; j++)
            for(int l = 1; l <= k; l++) {
                int r = x - a[j] * l;
                if(r < 0)
                    break;
                if(mp.find(r) == mp.end())
                    continue;
                ans = min(ans, l + mp[r]);
            }
        cout << (ans > k? -1 : ans) << '\n';
    }
    return 0;
}