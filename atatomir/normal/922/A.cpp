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

ll x, y, aux, o, c;

void no() {
    cout << "No";
    exit(0);
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> x >> y;
    c = x - y + 1;

    if (c & 1) no();
    c >>= 1;
    o = x - 2 * c;

    o = max(o, 0LL);
    c = max(c, 0LL);

    if (1 + o != y) no();
    if (o + 2 * c != x) no();
    if (o == 0 && c > 0) no();

    cout << "Yes";


    return 0;
}