#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 1000011
#define inf 1000000000

struct cmp {
    bool operator()(const int a, const int b) {
        return a > b;
    }
};

int n, i, v;
char s[30];

vector< pair<int, int> > ans;
priority_queue<int, vector<int>, cmp> H;



int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n", &n);
    for (i = 1; i <= n; i++) {
        scanf("%s", s + 1);

        if (s[1] != 'r') scanf("%d", &v);

        if (s[1] == 'i') {
            H.push(v);
            ans.pb(mp(1, v));
        }

        if (s[1] == 'r') {
            if (H.empty()) {
                H.push(0);
                ans.pb(mp(1, 0));
            }

            H.pop();
            ans.pb(mp(2, 0));
        }

        if (s[1] == 'g') {
            while (!H.empty()) {
                if (H.top() >= v) break;
                H.pop();
                ans.pb(mp(2, 0));
            }

            if (!H.empty()) {
                if (H.top() != v) {
                    H.push(v);
                    ans.pb(mp(1, v));
                }
            } else {
                H.push(v);
                ans.pb(mp(1, v));
            }

            ans.pb(mp(3, v));
        }

        scanf("\n");
    }

    printf("%d\n", ans.size());
    for (auto e : ans) {
        if (e.first == 1)
            printf("insert %d\n", e.second);

        if (e.first == 2)
            printf("removeMin\n");

        if (e.first == 3)
            printf("getMin %d\n", e.second);
    }

    return 0;
}