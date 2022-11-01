#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf ("%d", &n);

    vector <pair <int, int> > v;
    while (n--) {
        int s, d; scanf ("%d %d", &s, &d);
        
        int start = s;
        int finish = s + d - 1;

        sort(v.begin(), v.end());

        for (auto xx : v) { 
            if (start <= xx.first && finish >= xx.first || 
                (start >= xx.first && start <= xx.second)) {
                    if (start == s && finish == s + d - 1) {
                        start = 1;
                        finish = d;
                        break;
                    } else {
                        start = xx.second + 1;
                        finish = xx.second + d;
                    }
            }
        }

        for (auto xx : v) { 
            if (start <= xx.first && finish >= xx.first || 
                (start >= xx.first && start <= xx.second)) {
                    start = xx.second + 1;
                    finish = xx.second + d;
            }
        }

        v.push_back(make_pair(start, finish));
        printf ("%d %d\n", start, finish);
    }

    return 0;
}