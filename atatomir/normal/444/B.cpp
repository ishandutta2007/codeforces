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

#define maxN 100011

int def = 40;

ll n, d, x, i;
int a[maxN], b[maxN];
int ord[maxN];
vector<int> pos;

//x is 64-bit variable;
ll getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    int i;

    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld%lld", &n, &d, &x);
    initAB();
    def = min(def, (int)n);

    for (i = 0; i < n; i++)
        ord[a[i]] = i;

    for (i = 0; i < n; i++) {
        if (b[i] == 1) pos.pb(i);

        if (pos.size() == 0) {
            printf("%d\n", 0);
            continue;
        }

        bool found = false;
        for (int val = n; n - val < def; val--) {
            if (ord[val] > i) continue;
            if (b[i - ord[val]] == 0) continue;
            printf("%d\n", val);
            found = true;
            break;
        }

        if (found) continue;

        int ans = 0;
        for (auto e : pos)
            ans = max(ans, a[i - e]);

        printf("%d\n", ans);
    }

    return 0;
}