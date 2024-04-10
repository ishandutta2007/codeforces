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

ll i;
ll a00, a01, a10, a11;
ll x0, x1;

int how = 0;
vector<char> ans;


void no_sol() {
    printf("Impossible");
    exit(0);
}

void insert_to(int pos, char c) {
    ans.pb('0');
    for (int i = ans.size(); i > pos; i--) ans[i] = ans[i - 1];
    ans[pos] = c;
}

void full() {
    if (a01 == 0 && a10 == 0) {
        if (x0 > 1 && x1 > 1) no_sol();

        if (x0 * x1 == 1) {
            printf("1");
            exit(0);
        }

        if (x0 > 1) {
            for (i = 1; i <= x0; i++)
                printf("0");
        } else {
            for (i = 1; i <= x1; i++)
                printf("1");
        }

        exit(0);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld%lld%lld", &a00, &a01, &a10, &a11);

    x0 = sqrt(2 * a00) + 1;
    if ( (x0 - 1) * x0 != a00 * 2 ) no_sol();

    x1 = sqrt(2 * a11) + 1;
    if ( (x1 - 1) * x1 != a11 * 2 ) no_sol();

    full();

    if (a01 + a10 != x0 * x1) no_sol();

    ans.clear();
    for (i = 1; i <= x0; i++) ans.pb('0');

    // add right
    while (a01 >= x0) ans.pb('1'), a01 -= x0;
    if (a01 > 0) insert_to(a01, '1'), a10 -= x0 - a01, a01 = 0;

    // add left
    while (a10 >= x0) how++, a10 -= x0;

    if (a10 % x0 != 0) no_sol();

    for (i = 1; i <= how; i++)
        printf("1");
    for (auto e : ans)
        printf("%c", e);

    return 0;
}