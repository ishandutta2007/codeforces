#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

void bad() {
    cout << "-1" << endl;
    exit(0);
}

int main() {
    int n, d, h;
    cin >> n >> d >> h;
    if (h < (d + 1) / 2) {
        bad();
    }
    int nv = 2;
    int prv = 1;
    vector<pair<int, int>> result;
    for (int i = 1; i <= h; i++) {
        result.push_back(make_pair(prv, nv));
        prv = nv;
        nv++;
    }
    prv = 1;
    for (int i = 1; i <= d - h; i++) {
        result.push_back(make_pair(prv, nv));
        prv = nv;
        nv++;
    }
    if (n > 2 && d == 1) {
        bad();
    }
    int z = (h == d ? 2 : 1);
    while (nv != n + 1) {
        result.push_back(make_pair(z, nv));
        nv++;
    }
    for (pair<int, int> p : result) {
        cout << p.first << " " << p.second << endl;
    }
}

/*#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

vector<ll> v;
vector<pair<ll, ll>> ranges;
int n, k;

void normalize(vector<ll> & v) {
    ll carry = 0;
    for (size_t i = 0; i < v.size(); i++) {
        v[i] += carry;
        carry = 0;
        if (v[i] < 0) {
            carry += v[i];
            v[i] = -v[i];
        }
        if (v[i] > 0) {
            carry += v[i] / 2;
            v[i] %= 2;
        }
    }
    if (carry < 0) {
        for (size_t i = 0; i < ranges.size(); i++) {
            ranges[i].first *= -1;
            ranges[i].second *= -1;
            swap(ranges[i].first, ranges[i].second);
        }
    }
    else {
        while (carry > 0) {
            v.push_back(carry);
            carry = 0;
            if (v.back() > 0) {
                carry = v.back() / 2;
                v.back() %= 2;
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &k);
    v.resize(n + 1);
    ranges.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        int x;
        scanf("%d", &x);
        v[i] = x;
        ranges[i].first = -k - x;
        ranges[i].second = k - x;
    }

    normalize(v);
}
*/