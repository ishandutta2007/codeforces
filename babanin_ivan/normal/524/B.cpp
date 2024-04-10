#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

const int MAX_N = 1005;
const long long INF = 1000000000000000000ll;

int n;
pair< int, int > p[MAX_N];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    long long ans = INF;

    for (int i = 0; i < n; i++) {
        long long width = p[i].second;

        bool good = true;

        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            if (p[j].first > p[i].first && p[j].second > p[i].first) {
                good = false;
                break;
            }

            long long cur = INF;

            if (p[j].first > p[i].first) {
                cur = p[j].first;
            } else if (p[j].second > p[i].first) {
                cur = p[j].second;
            } else {
                cur = min(p[j].first, p[j].second);
            }

            width += cur;
        }

        if (good) {
            ans = min(ans, width * p[i].first);
        }

        swap(p[i].first, p[i].second);

        width = p[i].second;

        good = true;

        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            if (p[j].first > p[i].first && p[j].second > p[i].first) {
                good = false;
                break;
            }

            long long cur = INF;

            if (p[j].first > p[i].first) {
                cur = p[j].first;
            } else if (p[j].second > p[i].first) {
                cur = p[j].second;
            } else {
                cur = min(p[j].first, p[j].second);
            }

            width += cur;
        }

        if (good) {
            ans = min(ans, width * p[i].first);
        }
    }

    cout << ans << endl;

    return 0;
}