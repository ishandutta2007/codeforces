#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

const int INF = 1e9;

long long gcd(long long a, long long b) {
    if (a < b) {
        swap(a, b);
    }
    while (b != 0) {
        long long c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    multiset <int> s1;
    multiset <int> s2;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s1.insert(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s2.insert(x);
    }
    long long p1 = 0, p2 = 0;
    int now = 0;
    while (!s1.empty() || !s2.empty()) {
        if (now == 0) {
            now = 1;
        }
        else if (now == 1) {
            now = 2;
        }
        else {
            now = 1;
        }
        if (now == 1) {
            if (s1.size() == 0) {
                s2.erase(s2.find(*s2.rbegin()));
                continue;
            }
            if (s2.size() == 0) {
                p1 += *s1.rbegin();
                s1.erase(s1.find(*s1.rbegin()));
                continue;
            }
            if (*s1.rbegin() < *s2.rbegin()) {
                s2.erase(s2.find(*s2.rbegin()));
                continue;
            }
            else {
                p1 += *s1.rbegin();
                s1.erase(s1.find(*s1.rbegin()));
            }
        }
        if (now == 2) {
            if (s2.size() == 0) {
                s1.erase(s1.find(*s1.rbegin()));
                continue;
            }
            if (s1.size() == 0) {
                p2 += *s2.rbegin();
                s2.erase(s2.find(*s2.rbegin()));
                continue;
            }
            if (*s1.rbegin() > *s2.rbegin()) {
                s1.erase(s1.find(*s1.rbegin()));
                continue;
            }
            else {
                p2 += *s2.rbegin();
                s2.erase(s2.find(*s2.rbegin()));
            }
        }
    }
    cout << p1 - p2;
    return 0;
}