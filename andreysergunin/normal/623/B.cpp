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

vector<int> p;

const long long INF = 1e18;

void prime(int k) {
    for (int i = 2; i * i <= k; i++)
        if (k % i == 0) {
            while (k % i == 0)
                k /= i;
            p.push_back(i);
        }
    if (k > 1)
        p.push_back(k);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    long long a, b;
    cin >> n >> a >> b;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    prime(c[0]);
    prime(c[0] + 1);
    prime(c[0] - 1);
    long long ans = ((long long)n - 1) * a;
    for (int j = 0; j < p.size(); j++) {
        int q = p[j];
        long long cur = INF;
        vector<long long> best(n);
        long long pref = 0;
        if (c[0] % q != 0)
            pref = b;
        best[0] = pref;
        for (int i = 1; i < n; i++) {
            if (c[i] % q != 0) {
                if ((c[i] + 1) % q == 0 || (c[i] - 1) % q == 0)
                    pref = pref + b;
                else
                    pref = INF;
            }
            best[i] = min(best[i - 1] + a, pref);
        }
        long long suff = 0;
        cur = best[n - 1];
        ans = min(ans, cur);
        for (int i = n - 1; i >= 1; i--) {
            if (c[i] % q != 0) {
                if ((c[i] + 1) % q == 0 || (c[i] - 1) % q == 0)
                    suff = suff + b;
                else
                    suff = INF;
            }
            cur = best[i - 1] + suff;
            ans = min(ans, cur);
        }
    }
    p.clear();
    prime(c[n - 1]);
    prime(c[n - 1] + 1);
    prime(c[n - 1] - 1);
    
    for (int j = 0; j < p.size(); j++) {
        int q = p[j];
        long long cur = 0;
        long long suff = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (c[i] % q != 0) {
                if ((c[i] + 1) % q == 0 || (c[i] - 1) % q == 0)
                    suff = suff + b;
                else
                    suff = INF;
            }
            cur = (long long)i * a + suff;
            ans = min(ans, cur);
        }
    }
    cout << ans << endl;
    return 0;
}