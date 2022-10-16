#include <bits/stdc++.h>

// 1:01
using namespace std;

typedef long long int lint;
const lint INF = numeric_limits <lint> :: max();

int main() {
    int x = 28691, y = 28312;
    cin >> x >> y;

    pair <lint, int> ans(-INF, -1);
    if (y > 0) {
        for (int y_groups = 1; y_groups <= y; ++ y_groups)
            if (x >= y_groups - 1) {
                int gr_size = y / y_groups;
                int larger = y % y_groups;
                int smaller = y_groups - larger;

                lint decrease = 1LL * smaller * gr_size * gr_size + 1LL * larger * (gr_size + 1) * (gr_size + 1);
                lint add = 1LL * x * x;

                if (y_groups > 1) {
                    int one_groups = y_groups - 2;
                    int large_group = x - one_groups;
                    add = 1LL * large_group * large_group + one_groups;
                }

                ans = max(ans, {add - decrease, y_groups});
            }
    }
    else
        ans = {1LL * x * x, 0};

    lint prt;
    int y_groups;
    tie(prt, y_groups) = ans;

    cout << prt << endl;
    if (y_groups == 0) {
        for (int i = 0; i < x; ++ i)
            cout << "o";
        cout << endl;
        return 0;
    }

    int gr_size = y / y_groups;
    int larger = y % y_groups;
    int smaller = y_groups - larger;
    string larger_str, smaller_str;

    for (int i = 0; i < gr_size; ++ i)
        smaller_str += "x";
    for (int i = 0; i < gr_size + 1; ++ i)
        larger_str += "x";

    if (y_groups > 1) {
        int one_groups = y_groups - 2;
        int large_group = x - one_groups;

        string ans = smaller_str;
        smaller --;
        y_groups --;


        bool doneAll = false;
        while (y_groups --) {
            if (!doneAll) {
                for (int i = 0; i < large_group; ++ i)
                    ans += "o";
                doneAll = true;
            }
            else
                ans += "o";

            if (smaller) {
                smaller --;
                ans += smaller_str;
            }
            else if (larger) {
                larger --;
                ans += larger_str;
            }
        }

        cout << ans << endl;
    }
    else {
        for (int i = 0; i < x; ++ i)
            cout << "o";
        for (int i = 0; i < y; ++ i)
            cout << "x";
        cout << endl;
        return 0;
    }

    return 0;
}