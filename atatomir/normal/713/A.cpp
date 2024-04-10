#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

int n, i;
char op;
ll nr;
map<ll, int> M;

ll pre(ll nr) {
    ll aux = 0;
    int cnt = 0, i;

    while (nr) {
        if ( (nr % 10) % 2 == 0 )
            aux = aux * 10;
        else
            aux = aux * 10 + 1;

        nr /= 10;
        cnt++;
    }

    ll ans = 0;
    for (i = 1; i <= cnt; i++) {
        ans = ans * 10 + (aux % 10);
        aux /= 10;
    }

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n", &n);
    M.clear();

    for (i = 1; i <= n; i++) {
        scanf("%c %lld\n", &op, &nr);
        nr = pre(nr);

        if (op == '+')
            M[nr]++;

        if (op == '-')
            M[nr]--;

        if (op == '?')
            printf("%d\n", M[nr]);
    }


    return 0;
}