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

#define maxN 500011

int n, i, x, bit, ans0, ans1;
string s;
vector< pair<char, int> > op;

int to_and, to_or, to_xor;

int run(int bit, int val) {
    int act;

    for (auto e : op) {
        act = (e.second >> bit) & 1;
        if (e.first == '&')
            val &= act;
        if (e.first == '|')
            val |= act;
        if (e.first == '^')
            val ^= act;
    }

    return val;
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> s >> x;
        op.pb(mp(s[0], x));
    }

    to_and = 1024 - 1;
    to_xor = 0;
    to_or = 0;

    for (bit = 0; bit < 10; bit++) {
        ans0 = run(bit, 0);
        ans1 = run(bit, 1);

        if (ans0 == 0 && ans1 == 1) {
            //! do not do anyhting
        }

        if (ans0 == 0 && ans1 == 0) {
            to_and ^= (1 << bit);
        }

        if (ans0 == 1 && ans1 == 0) {
            to_xor ^= (1 << bit);
        }

        if (ans0 == 1 && ans1 == 1) {
            to_or ^= (1 << bit);
        }
    }

    printf("3\n");
    printf("| %d\n", to_or);
    printf("& %d\n", to_and);
    printf("^ %d\n", to_xor);




    return 0;
}