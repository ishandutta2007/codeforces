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

ll k, n, s, p;
ll sheets, total, need;

int main()
{
    //freopen("test.in","r",stdin);

    cin >> k >> n >> s >> p;

    sheets = (n + s - 1) / s;
    total = k * sheets;
    need = (total + p - 1) / p;

    cout << need;

    return 0;
}