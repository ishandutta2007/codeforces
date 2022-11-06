#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int query(string str, int i, int j) {
    cout << str << ' ' << i << ' ' << j << endl;
    int resp;
    cin >> resp;
    if (resp == -1)
        exit(0);
    return resp;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 2; i <= n; ++i)
        a[i] = query("XOR", 1, i);


    for (int mask : {1, (1 << 20) - 2}) {
        map<int, int> mp;
        for (int i = 1; i <= n; ++i)
            if (!mp.count(a[i] & mask))
                mp[a[i] & mask] = i;
            else {
                const int j = mp.at(a[i] & mask);
                int x = (query("OR", j, i) ^ a[i]) & mask;
                for(int i = 1; i <= n; ++i)
                    a[i] ^= x;
                break;
            }
            assert(mp.size() < n);
    }
    cout << "!";
    for(int i = 1; i <= n; ++i)
        cout << ' ' << a[i];
    cout << endl;


    return 0;
}