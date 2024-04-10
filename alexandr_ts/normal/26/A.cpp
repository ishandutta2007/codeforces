#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const int N = 1e4;

bool used[N];
unordered_set <int> pr;

int main() {
    ll n;
    cin >> n;
    used[0] = used[1] = true;
    frab(i, 2, n + 1)
        if (!used[i])
            for (int j = i * 2; j <= n; j += i)
                used[j] = true;
    fr(i, n + 1)
        if (!used[i])
            pr.insert(i);
    ll ans = 0;
    frab(i, 1, n + 1) {
        int cnt = 0;
        frab(j, 1, i + 1)
            if (i % j == 0 && pr.count(j)) {
                cnt++;
                //cout << j << " ";
            }
        if (cnt == 2) {
            ans++;
            //cout << i << endl;
        }
    }
    cout << ans;

}