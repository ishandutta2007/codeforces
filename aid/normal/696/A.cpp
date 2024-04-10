#include <iostream>
#include <map>

using namespace std;

map<long long, long long> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    for(int qq = 0; qq < q; qq++) {
        int t;
        cin >> t;
        if(t == 1) {
            long long v, u, w;
            cin >> v >> u >> w;
            while(v != u) {
                if(v < u)
                    swap(v, u);
                mp[v] += w;
                v /= 2;
            }
        }
        else {
            long long v, u;
            cin >> v >> u;
            long long ans = 0;
            while(v != u) {
                if(v < u)
                    swap(v, u);
                ans += mp[v];
                v /= 2;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}