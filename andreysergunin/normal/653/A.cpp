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

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    n = unique(a.begin(), a.end()) - a.begin();
    for (int i = 0; i < n - 2; i++) {
        if (a[i + 2] - a[i] <= 2) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" <<endl;
    return 0;
}