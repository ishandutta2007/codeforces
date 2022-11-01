#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

const int MAX_M = 100005;

int m, k, a[MAX_M], type[MAX_M], unsat[MAX_M], last[MAX_M];

int main() {
    int tests;

    scanf("%d", &tests);

    for (int test_id = 0; test_id < tests; test_id++) {
        scanf("%d %d", &m, &k);

        for (int i = 0; i < k; i++) {
            scanf("%d", &a[i]);

            last[i] = -1;
        }

        int idx = -1, cnt_uncertain = 0;

        for (int i = 0; i < m - 1; i++) {
            scanf("%d %d", &type[i], &unsat[i]);

            type[i]--;

            if (type[i] >= 0) {
                last[type[i]] = i;
            }

            if (idx < 0) {
                if (unsat[i]) {
                    idx = i;
                } else if (type[i] >= 0) {
                    a[type[i]]--;
                } else {
                    cnt_uncertain++;
                }
            }
        }

        if (idx < 0) {
            idx = m;
        }

        string s(k, 'N');

        int mx_del = 0;

        for (int i = 0; i < k; i++) {
            if (last[i] < idx && a[i] <= cnt_uncertain) {
                s[i] = 'Y';

                mx_del = max(mx_del, cnt_uncertain - a[i]);
            }
        }
        
        for (int i = idx; i < m - 1; i++) {
            if (type[i] < 0) {
                mx_del++;
            } else {
                a[type[i]]--;
            }
        }

        for (int i = 0; i < k; i++) {
            if (a[i] <= mx_del) {
                s[i] = 'Y';
            }
        }

        cout << s << endl;
    }

    return 0;
}