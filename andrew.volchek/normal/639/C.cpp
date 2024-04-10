#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

vector<ll> v;
vector<pair<ll, ll>> ranges;
int n, k, sign = 1;

void normalize() {
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
        sign = -1;
        v.push_back(carry);
        for (size_t i = 0; i < ranges.size(); i++) {
            ranges[i].first *= -1;
            ranges[i].second *= -1;
            swap(ranges[i].first, ranges[i].second);
        }
        for (ll & x : v) {
            x = -x;
        }
        normalize();
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

bool inRange(pair<ll, ll> range, ll x) {
    return x >= range.first && x <= range.second;
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
    ll forbidden = v[n];
    normalize();
    forbidden *= sign;
    while (ranges.size() < v.size()) {
        ranges.push_back(make_pair(1LL, -1LL));
    }
    int cntSmaller = 0, cntWas = 0;
    for (ll x : v) {
        if (x != 0) cntSmaller++;
    }
    ll cur = 0;
    int result = 0;
    for (int i = (int)v.size() - 1; i >= 0; i--) {
        if (v[i] != 0) {
            cur = cur * 2 + v[i];
            cntSmaller--;
            cntWas++;
        }
        else {
            cur *= 2;
        }
        if (cntSmaller == 0) {
            if (inRange(ranges[i], -cur) && !(i == n && cur == forbidden)) result++;
        }
        if (!inRange(make_pair(-2LL * k - 1, 2LL * k + 1), cur)) break;
    }

    cout << result << endl;
}