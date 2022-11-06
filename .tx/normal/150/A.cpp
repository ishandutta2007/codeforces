#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long lint;

vector<int> divs;

void fillDiv(lint q) {
    for (lint i = 2; i * i <= q; i++) {
        if (q % i == 0) {
            divs.push_back(i);
            if (q / i != i) {
                divs.push_back(q / i);
            }
        }
    }
}

map<lint, lint> m;

lint go(lint x) {
    if (m.find(x) != m.end()) {
        return m[x];
    }
    bool isPrime = true;
    for (int i = 0; i < divs.size() && divs[i] < x; i++) {
        if (x % divs[i] == 0) {
            lint mv = go(divs[i]);
            if (mv == -1) {
                return m[x] = divs[i];
            }
            isPrime = false;
        }
    }
    return m[x] = (isPrime ? 0 : -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    lint q;
    cin >> q;
    fillDiv(q);
    if (divs.empty()) {
        cout << 1 << endl << 0;
        return 0;
    }

    sort(divs.begin(), divs.end());

    lint t = go(q);
    if (t == -1) {
        cout << 2;
    } else {
        cout << 1 << endl << t;
    }


    return 0;
}