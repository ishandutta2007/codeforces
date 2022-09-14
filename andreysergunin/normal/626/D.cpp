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
#include <queue>

using namespace std;

const int MAXC = 5010;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<long long> p(MAXC);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            p[a[j] - a[i]]++;
    vector<long long> suff(MAXC + 1);
    suff[MAXC] = 0;
    for (int i = MAXC - 1; i >= 0; i--)
        suff[i] = suff[i + 1] + p[i];
    double ans = 0;
    for (int i = 0; i < MAXC; i++)
        for (int j = 0; j < MAXC; j++) {
            if (i + j + 1 >= MAXC)
                continue;
            ans += (double)8 * p[i] / n / (n - 1) * p[j] / n / (n - 1) * suff[i + j + 1] / n / (n - 1);
        }
    printf("%.12lf", ans);
    return 0;
}