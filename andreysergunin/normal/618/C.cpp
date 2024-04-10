#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>

using namespace std;

long long crossProduct(pair<long long, long long> a, pair<long long, long long> b) {
    return a.first * b.second - a.second * b.first;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector< pair< pair<int, int>, int> > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 2; i < n; i++) {
        pair<int, int> x = make_pair(a[0].first.first - a[1].first.first,
                                     a[0].first.second - a[1].first.second);
        pair<int, int> y = make_pair(a[0].first.first - a[i].first.first,
                                     a[0].first.second - a[i].first.second);
        if (crossProduct(x, y) != 0) {
            cout << a[0].second << " " << a[1].second << " " <<  a[i].second;
            return 0;
        }
    }
    return 0;
}