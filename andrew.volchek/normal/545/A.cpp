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


int bad[105];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 1 || x == 3)
                bad[i] = 1;
        }
    }

    vector < int > ans;
    for (int i = 0; i < n; i++) {
        if (!bad[i])
            ans.pb(i);
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        if (i)
            cout << " " ;
        cout << ans[i] + 1;
    }

    return 0;
}