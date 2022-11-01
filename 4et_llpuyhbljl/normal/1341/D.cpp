#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
#include<bitset>
using namespace std;
const unsigned long long INF = 1e17;
const int Y = 100100;
const long long A = 179, m = 1000000007, m2 = 1000000009;
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
int arr[2000];
int msk[10];
bitset<3001>cost[2001];
void build() {
    msk[0] = 119;
    msk[1] = 36;
    msk[2] = 93;
    msk[3] = 109;
    msk[4] = 46;
    msk[5] = 107;
    msk[6] = 123;
    msk[7] = 37;
    msk[8] = 127;
    msk[9] = 111;
}
int Get() {
    int r = 0;
    for (int i = 0; i <= 6 ; ++i) {
        char tmp;
        cin >> tmp;
        r |= ((1 << i) * (tmp == '1'));
    }
    return r;
}
int Gc(int i, int j) {
    int r = 0;
    j = msk[j];
    for (int ii = 0; ii <= 6; ++ii) {
        if ((j & (1 << ii)) != 0) {
            if ((i & (1 << ii)) == 0) {
                ++r;
            }
        }
    }
    return r;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    build();
    for (int i = 0; i < n; ++i)arr[i] = Get();
    cost[n][0] = true;
    for (int i = n - 1; i >= 0; --i) {
        bitset<3001>tt;
        for (int j = 0; j < 10; ++j) {
            if ((arr[i] | msk[j]) == msk[j]) {
                int tmp = Gc(arr[i], j);
                tt[tmp] = true;
            }
        }
        for (int j = 0; j <= k; ++j) {
            if (cost[i + 1][j]) {
                cost[i] |= tt << j;
            }
        }
    }
    if (!cost[0][k]) {
        cout << -1;
        return 0;
    }
    vector<int>Vd;
    for (int i = 0; i < n; ++i) {
        int r;
        int c = 0;
        for (int j = 0; j < 10; ++j) {
            if ((arr[i] | msk[j]) == msk[j]) {
                int tmp = Gc(arr[i], j);
                if (tmp <= k && cost[i + 1][k - tmp]) {
                    r = j;
                    c = tmp;
                }
            }
        }
        k -= c;
        Vd.push_back(r);
    }
    for (auto x : Vd)cout << x;
    return 0;
}