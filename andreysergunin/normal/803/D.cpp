#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

const int INF = 1e9;
const int MAXN = 1111;

int nxt[MAXN][2 * MAXN];

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = sz(s);

    vector<int> a;
    int len = 0;
    for (int i = 0; i < n; ++i) {
        ++len;
        if (s[i] == ' ' || s[i] == '-') {
            a.push_back(len);
            len = 0;
        }
    }
    if (len > 0) {
        a.push_back(len);
    }

    int l = 0, r = n;
    n = sz(a);

    while (r - l > 1) {
        int mid = (l + r) / 2;
        int cur = 0;
        int cnt = 1;

        bool f = true;

        for (int i = 0; i < n; ++i) {
            if (a[i] > mid) {
                f = false;
                break;
            }

            cur += a[i];
            if (cur > mid)  {
                cur = a[i];
                ++cnt;
            }
        }

        if (!f || cnt > k) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << r << endl;

    return 0;
}