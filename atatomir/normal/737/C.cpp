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

#define maxN 200011

int n, s, i;
int a[maxN];
bool used[maxN];
vector<int> pos;
int ans, rez;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &s);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);

        if (a[i] == 0) {
            if (i != s) {
                ans++;
                rez++;
            }
        } else {
            if (i == s) {
                ans++;
                continue;
            }

            used[a[i]] = true;
            pos.pb(a[i]);
        }
    }

    for (i = 1; i <= n && rez > 0; i++) {
        if (used[i]) continue;
        used[i] = true;
        rez--;
    }

    sort(pos.begin(), pos.end());

    for (i = 1; i <= n; i++) {
        if (used[i]) continue;
        if (pos.empty()) break;
        if (pos.back() <= i) break;

        ans++;
        pos.pop_back();
        used[i] = true;
    }

    printf("%d", ans);


    return 0;
}