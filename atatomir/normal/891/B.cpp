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

#define maxN 33

int n, i;
int a[maxN], b[maxN];
pair<int, int> ord[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;

    for (i = 1; i <= n; i++) {
        cin >> a[i];
        ord[i] = mp(a[i], i);
    }

    sort(ord + 1, ord + n + 1);
    ord[n + 1] = ord[1];
    for (i = 1; i <= n; i++) {
        b[ ord[i].second ] = ord[i + 1].first;
    }

    for (i = 1; i <= n; i++)
        cout << b[i] << ' ';


    return 0;
}