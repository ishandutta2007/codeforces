#include <bits/stdc++.h>

#define fc first
#define sc second
#define pb push_back
#define ll long long
#define ld long double

using namespace std;

vector <ll> cur;
int need;
void rec(ll x) {
    if (x == need) {
        puts("YES");
        printf("%d\n", cur.size());
        for (auto c : cur) {
            printf("%d ", c);
        }
        puts("");
        exit(0);
    } else {
        if (x > need) return;
        cur.pb(x * 10 + 1);
        rec(x * 10 + 1);
        cur.pop_back();
        cur.pb(x * 2);
        rec(x * 2);
        cur.pop_back();
    }
}

int main() {
    #ifdef ONPC
        freopen("a.in", "r", stdin);
        freopen("a.out", "w", stdout);
    #else
        //
        //
    #endif
    int a, b;
    scanf("%d%d", &a, &b);
    cur.pb(a);
    need = b;
    rec(a);
    puts("NO");
}