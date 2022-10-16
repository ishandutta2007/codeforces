#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 55;
int p[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    long long m;
    cin >> n >> m;
    m--;
    int l = 0, r = n;
    for(int i = 0; i < n; i++) {
        long long cnt = (i == n - 1? 0 : (1ll << (n - i - 2)));
        if(cnt <= m) {
            p[r - 1] = i;
            r--;
            m -= cnt;
        }
        else {
            p[l] = i;
            l++;
        }
    }
    for(int i = 0; i < n; i++)
        cout << p[i] + 1 << ' ';
    cout << '\n';
    return 0;
}