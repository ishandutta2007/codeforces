#include <bits/stdc++.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

char s[1111111];
int d[1111111];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    int cf = 0;
    int mx = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'F') {
            cf++;
        } else if (cf > 0) {
            mx = max(mx + 1, cf);
        }
    }

    cout << mx;



    return 0;
}