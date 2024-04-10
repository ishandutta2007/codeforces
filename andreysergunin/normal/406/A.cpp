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

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector< vector<int> > a(n);
    for (int i = 0; i < n; i++)
        a[i].reserve(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    int q;
    cin >> q;
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = (ans + a[i][i]) % 2;
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 3)
            printf("%d", ans);
        else {
            int k;
            scanf("%d", &k);
            ans = 1 - ans;
        }
    }
    
    return 0;
}