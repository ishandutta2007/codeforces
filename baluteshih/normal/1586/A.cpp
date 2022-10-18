#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int MAXC = 20000;
int arr[105], not_prime[20005] = {1, 1};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 2; i <= MAXC; ++i)
        if (!not_prime[i])
            for (int j = i + i; j <= MAXC; j += i)
                not_prime[j] = 1;
    int t;
    cin >> t;
    while (t--) {
        int n, sum = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> arr[i], sum += arr[i];
        if (not_prime[sum]) {
            cout << n << "\n";
            for (int i = 1; i <= n; ++i)
                cout << i << " \n"[i == n];
            continue;
        }
        int flag = 0;
        for (int i = 1; i <= n; ++i)
            if (not_prime[sum - arr[i]]) {
                cout << n - 1 << "\n";
                for (int j = 1; j < i; ++j)
                    cout << j << " ";
                for (int j = i + 1; j <= n; ++j)
                    cout << j << " ";
                cout << "\n";
                flag = 1;
                break;
            } 
        for (int i = 1; i <= n && !flag; ++i)
            for (int j = i + 1; j <= n && !flag; ++j)
                if (not_prime[sum - arr[i] - arr[j]]) {
                    cout << n - 2 << "\n";
                    for (int k = 1; k < i; ++k)
                        cout << k << " ";
                    for (int k = i + 1; k < j; ++k)
                        cout << k << " ";
                    for (int k = j + 1; k <= n; ++k)
                        cout << k << " ";
                    cout << "\n";
                    flag = 1;
                    break;
                }
        assert(flag);
    }
}