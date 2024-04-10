#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011

const ll n = 100001;
const ll s1 = 34;
const ll s2 = 32;
const ll s3 = 2;
const string ss1 = "What are you doing while sending \"";
const string ss2 = "\"? Are you busy? Will you send \"";
const string ss3 = "\"?";
const string ini = "What are you doing at the end of the world? Are you busy? Will you save us?";

ll i, q;
ll f[maxN];
ll id, pos;

void pre() {
    f[0] = 75;
    for (i = 1; i <= n; i++) {
        f[i] = 2 * f[i - 1] + s1 + s2 + s3;
        f[i] = min(f[i], 1LL << 60);
    }
}

char solve() {
    if (f[id] < pos) return '.';

    if (id == 0) return ini[pos - 1];

    if (pos <= s1)
        return ss1[pos - 1];
    pos -= s1;

    if (pos <= f[id - 1]) {
        id--;
        return solve();
    }
    pos -= f[id - 1];

    if (pos <= s2)
        return ss2[pos - 1];
    pos -= s2;

    if (pos <= f[id - 1]) {
        id--;
        return solve();
    }
    pos -= f[id - 1];

    if (pos <= s3)
        return ss3[pos - 1];
    pos -= s3;

    cerr << "Error!";
}

int main()
{
    //freopen("test.in","r",stdin);

    pre();
    cin >> q;
    for (i = 1; i <= q; i++) {
        cin >> id >> pos;
        cout << solve();
    }



    return 0;
}