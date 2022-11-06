#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 2076
typedef bitset<maxN> bs;

const int bits = 16;
const int mask = (1 << bits) - 1;

int n, i;
char s[maxN];

bool used[maxN];
bs conf[maxN], prov[maxN];
bs act;

void get_number(int n, char *s, bs& ans) {
    int i, aux, pos;
    static vector<int> data;

    ans.reset(); pos = 0;
    data.resize(2016);
    for (i = 1; i <= n; i++) data[n - i + 1] = s[i] - '0';

    while (n > 0) {
        aux = 0;

        for (i = n; i > 0; i--) {
            aux = aux * 10 + data[i];
            data[i] = aux >> bits;
            aux &= mask;
        }

        for (i = 0; i < bits; i++)
            ans[pos++] = (aux >> i) & 1;

        while (n > 0 && data[n] == 0) n--;
    }
}

void add_number(bs& data, int id) {
    static bs from;
    static vector<int> ans;
    int i;

    from.reset();
    from[id] = 1;

    for (int i = 2000; i >= 0; i--) {
        if (data[i] == 0) continue;

        if (!used[i]) {
            used[i] = true;
            prov[i] = from;
            conf[i] = data;

            printf("0\n");
            return;
        } else {
            from = from ^ prov[i];
            data = data ^ conf[i];
        }
    }

    ans.clear();
    for (i = 1; i <= 2000; i++)
        if (from[i] == 1 && i != id)
            ans.pb(i);

    printf("%d ", ans.size());
    for (auto e : ans)
        printf("%d ", e - 1);
    printf("\n");
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n", &n);
    for (i = 1; i <= n; i++) {
        memset(s, 0, sizeof(s));
        scanf("%s\n", s + 1);
        get_number(strlen(s + 1), s, act);
        add_number(act, i);
    }


    return 0;
}