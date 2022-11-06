#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 200011;

int n, i;
char s[maxN];
vector<int> zero, one;
vector< vector<int> > ans;

int main()
{
   // freopen("test.in","r",stdin);

    scanf("%s", s + 1);
    n = strlen(s + 1);

    for (i = 1; i <= n; i++) {
        if (s[i] == '0') {
            if (one.empty()) {
                ans.emplace_back();
                ans.back().pb(i);
                zero.pb(ans.size() - 1);
            } else {
                int x = one.back(); one.pop_back();
                ans[x].pb(i);
                zero.pb(x);
            }
        } else {
            if (zero.empty()) {
                printf("-1");
                return 0;
            } else {
                int x = zero.back(); zero.pop_back();
                ans[x].pb(i);
                one.pb(x);
            }
        }
    }

    if (!one.empty()) {
        printf("-1");
        return 0;
    }

    printf("%d\n", ans.size());
    for (auto v : ans) {
        printf("%d ", v.size());
        for (auto e : v) printf("%d ", e);
        printf("\n");
    }


    return 0;
}