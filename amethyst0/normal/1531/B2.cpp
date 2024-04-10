#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int maxn = (int)1e5 + 10;
map <int, int> cnt;
map <pair <int, int>, int> numb;

int main() {
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x > y) {
            swap(x, y);
        }
        if (x == y) {
            ans += cnt[x];
            cnt[x]++;
        } else {
            ans += cnt[x] + cnt[y];
            cnt[x]++;
            cnt[y]++;
            ans -= numb[make_pair(x, y)];
            numb[make_pair(x, y)]++;
        }
    }
    
    cout << ans << '\n';
}