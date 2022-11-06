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

#define maxN 1000011

int n, i, j;
vector<int> divs[maxN];

int d1[maxN], d2[maxN];

void add_number(int nr) {
    int d;

    for (auto d : divs[nr]) {
        if (d >= nr) continue;

        d2[nr - d + 1]++;
        d2[nr + 1]--;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;

    for (i = 2; i <= n; i++) {
        if (divs[i].size()) continue;
        for (j = i; j <= n; j += i) divs[j].pb(i);
    }

    memset(d1, 0, sizeof(d1));
    d1[n]++;

    for (int tms = 1; tms <= 2; tms++) {
        memset(d2, 0, sizeof(d2));

        for (i = 3; i <= n; i++) {
            if (d1[i] == 0) continue;

            add_number(i);
        }

        for (i = 1; i <= n; i++) d2[i] += d2[i - 1];
        memcpy(d1, d2, sizeof(d1));
    }

    for (i = 3; d1[i] == 0; i++);
    cout << i;


    return 0;
}