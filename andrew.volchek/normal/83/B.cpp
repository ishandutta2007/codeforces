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


const int maxn = 1e5 + 5;
ll need[maxn];

int main()
{

#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif

    int n;
    ll k;
    cin >> n >> k;

    vector<pair<ll,int>> a;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a.pb(mp(x, i));
    }

    sort(a.begin(), a.end());

    ll t = 0;
    ll was = 0;
    ll left = n;
    set<int> present;

    for (int i = 0; i < a.size(); i++) {
        int j = i;
        while (j < a.size() && a[i].fst == a[j].fst) {
            j++;
        }


        if (t + (a[i].fst - was) * left <= k) {
           // k -= t + (a[i].fst - was) * left;
            t += (a[i].fst - was) * left;
            left -= j - i;
            was = a[i].fst;
        } else {
            ll g = max(0LL, (k - t) / left - 2);
            was += g;
            t += g * left;

            for (int h = i; h < n; h++) {
                need[a[h].snd] = a[h].fst;
                present.insert(a[h].snd);
            }

            int mid = *present.begin() - 1;
            while (true) {
                if (t == k) {
                    vector<int> ans(present.begin(), present.end());
                    int p = upper_bound(ans.begin(), ans.end(), mid) - ans.begin();
                    if (p == ans.size()) {
                        p = 0;
                    }
                    for (int i = p; i < ans.size(); i++) {
                        printf("%d ", ans[i] + 1);
                    }
                    for (int i = 0; i < p; i++) {
                        printf("%d ", ans[i] + 1);
                    }
                    return 0;
                }
                vector<int> del;
                for (int x : present) {
                    t++;
                    need[x]--;
                    if (need[x] == was) {
                        del.pb(x);
                    }
                    if (t == k) {
                        mid = x;
                        break;
                    }
                }
                for (int x : del) {
                    present.erase(x);
                }
            }
        }

        i = j - 1;
    }

    if (t == k) {

    } else {
        cout << -1 << endl;
    }

    return 0;
}