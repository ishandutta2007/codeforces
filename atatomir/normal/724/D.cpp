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
#define sigma 26

int n, m, i, step;
char s[maxN];
int cnt[sigma + 11];
vector<char> ans;

int sol;

bool fill_works(char chlim, int l, int r) {
    int i, todo, last;

    todo = l + m - 1;
    last = 0;

    for (i = l; i < r; i++) {
        if (s[i] == chlim)
            last = i;

        if (i >= todo) {
            if (last == 0) return false;
            todo = last + m;
            sol++;
            last = 0;
        }
    }

    if (todo < r) return false;

    return true;
}

bool check(int limit) {
    int i, j, l, r, last;
    char chlim = 'a' + limit;

    sol = 0;
    for (i = 1; i <= n; i = r + 1) {
        l = i;
        for (r = i; s[r] >= chlim && r <= n; r++);
        if (r - l < m) continue;

        if (!fill_works(chlim, l, r))
            return false;
    }

    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n%s", &m, s + 1);
    n = strlen(s + 1);

    for (i = 1; i <= n; i++) cnt[s[i] - 'a']++;

    for (step = 0; step < sigma; step++) {
        if (check(step)) {
            for (i = 1; i <= sol; i++) ans.pb('a' + step);
            break;
        }

        for (i = 1; i <= cnt[step]; i++) ans.pb('a' + step);
    }


    for (auto e : ans) printf("%c", e);

    return 0;
}