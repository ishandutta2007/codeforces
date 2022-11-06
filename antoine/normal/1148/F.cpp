#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int leadingBit(const ll mask) {
    for (int i = 61; i >= 0; --i)
        if (mask & (1LL << i))
            return i;
    assert(0);
    return -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> val(n), msk(n);

    vector<int> b[62];
    for (int i = 0; i < n; ++i) {
        cin >> val[i] >> msk[i];
        b[leadingBit(msk[i])].push_back(i);
    }

    {
        const ll sum = accumulate(val.begin(), val.end(), 0LL);
        assert(sum);
        if (sum < 0)
            for (int i = 0; i < n; ++i)
                val[i] *= -1;
    }

    ll ans = 0;
    for (int bit = 0; bit < 62; ++bit) {
        ll sum = 0;
        for (const int i : b[bit])
            sum += val[i];
        if (sum > 0) {
            ans |= 1LL << bit;
            for (int i = 0; i < n; ++i)
                if (msk[i] & (1LL << bit))
                    val[i] *= -1;
        }
    }
    cout << ans;
    return 0;
}