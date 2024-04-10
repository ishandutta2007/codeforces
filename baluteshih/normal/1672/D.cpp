#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int arr[200005], brr[200005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> arr[i];
        for (int i = 1; i <= n; ++i)
            cin >> brr[i];
        int flag = 1;
        multiset<int> ms;
        for (int i = n, nw = n; i >= 1 && flag; --i) {
            int done = 0;
            while ((nw == 0 || arr[i] != brr[nw]) && flag) {
                if (i == n || nw == 0 || arr[i + 1] != brr[nw]) {
                    if (ms.find(arr[i]) == ms.end())
                        flag = 0;
                    else {
                        ms.erase(ms.find(arr[i]));
                        done = 1;
                        break;
                    }
                }
                else
                    ms.insert(brr[nw]), --nw;
            }
            if (!flag) break;
            if (!done)
                --nw;
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}