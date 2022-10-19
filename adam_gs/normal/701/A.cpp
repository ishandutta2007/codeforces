#include <bits/stdc++.h>

using namespace std;

#define nl cout << '\n'

bool srt(pair <int, int> a, pair <int, int> b) {
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;
    pair <int, int> tab[n];
    for (int i = 0; i < n; ++i) {
        cin >> tab[i].first;
        tab[i].second=i+1;
    }
    sort(tab, tab+n, srt);
    for (int i = 0; i < n/2; ++i) {
        cout << tab[i].second << " " << tab[n-i-1].second;
        nl;
    }
}