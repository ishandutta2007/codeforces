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

using namespace std;

const int MAXN = 1e6;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    int a[MAXN];
    for (int i = 0; i < MAXN; i++)
        a[i] = 0;
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        a[k - 1] = 1;
    }
    vector<int> ans;
    int m = 0;
    for (int i = 0; i < MAXN; i++) {
        if (a[i] == 1 && a[MAXN - i - 1] == 0)
            ans.push_back(MAXN - i);
        if (a[i] == 1 && a[MAXN - i - 1] == 1)
            ++m;
    }
    for (int i = 0; i < MAXN / 2; i++) {
        if (m > 0 && a[i] == 0 && a[MAXN - i - 1] == 0) {
            ans.push_back(MAXN - i);
            ans.push_back(i + 1);
            m -= 2;;
        }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++)
        printf("%d ", ans[i]);
    return 0;
}