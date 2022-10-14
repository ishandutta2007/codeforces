#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
ll cnt[30][2];
struct bst {
    int sz = 0, lv;
    bst *ch[2]{};
    bst(int _lv) : lv(_lv) {}
    void insert(int i) {
        ++sz;
        if (lv == -1) return;
        if (ch[~i >> lv & 1]) cnt[lv][i >> lv & 1] += ch[~i >> lv & 1]->sz;
        if (!ch[i >> lv & 1]) ch[i >> lv & 1] = new bst(lv - 1);
        ch[i >> lv & 1]->insert(i);
    }
} rt(30);
int main() {
    int n;
    cin >> n;
    for (int i = 0, x; i < n; ++i) cin >> x, rt.insert(x);
    int k = 0;
    ll ans = 0;
    for (int i = 0; i < 30; ans += min(cnt[i][0], cnt[i][1]), ++i) if (cnt[i][1] < cnt[i][0]) k ^= 1 << i;
    cout << ans << ' ' << k;
}