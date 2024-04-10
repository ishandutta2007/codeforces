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


vector<int> a;

bool check(int k) {
    if (k % 2 == 0)
        if (a[k] >= a[k + 1])
            return false;
    if (k % 2 == 1)
        if (a[k] <= a[k + 1])
            return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> f;
    for (int i = 0; i < n - 1; i++) {
        if (!check(i))
            f.push_back(i);
    }
    if (f.size() > 4) {
        cout << 0;
        return 0;
    }
    
    int ans = 0;
    
    for (int t = 0; t < 2; t++) {
        int k = f[0] + t;
        for (int i = 0; i < n; i++) {
            if (k == f[0] + 1 && i == f[0])
                continue;
            swap(a[k], a[i]);
            bool fl = true;
            
            if (0 < i && !check(i - 1))
                fl = false;
            if (i < n - 1 && !check(i))
                fl = false;
            
            if (0 < k && !check(k - 1))
                fl = false;
            if (k < n - 1 && !check(k))
                fl = false;
            
            for (int j = 0; j < f.size(); j++)
                if (f[j] < n - 1 && !check(f[j]))
                    fl = false;
            
            if (fl)
                ++ans;
            swap(a[k], a[i]);
        }
    }
    cout << ans << endl;
    return 0;
}