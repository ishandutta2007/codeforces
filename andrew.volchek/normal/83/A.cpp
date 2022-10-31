#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <cstdlib>
#include <time.h>
#include <cassert>
#include <locale.h>
#include <bitset>
#include <fstream>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define y0 asdfasdf
#define y1 fdsafdsa

template<typename T> T sqr(T x) {
    return x * x;
}




int main()
{

#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif

    int n;
    cin >> n;
    ll ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && a[i] == a[j]) {
            j++;
        }
        ans += 1LL * (j - i) * (j - i + 1) / 2;
        i = j - 1;
    }

    cout << ans << endl;


    return 0;
}