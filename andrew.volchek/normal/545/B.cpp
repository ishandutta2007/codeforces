#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <string>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld lond double
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}


int main() {
    //freopen("a.in", "r", stdin);
    string a, b;
    cin >> a;
    cin.ignore();
    cin >> b;
    int n = a.size();
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            c++;
    }

    if (c & 1) {
        cout << "impossible" << endl;
        return 0;
    }

    string ans;
    int p = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i])
            ans += a[i];
        else {
            if (p < c / 2) {
                ans += a[i];
            } else {
                ans += b[i];
            }
            p++;
        }
    }

    cout << ans << endl;

    return 0;
}