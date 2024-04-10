#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int MAXN = 100000 + 500;
int a[MAXN + 1], b[MAXN + 1], c[MAXN + 1], d[MAXN + 1];
vector<ll> v;

int main() {
    //ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    v.push_back(1);
    while(v.size() < 60) {
        ll was = v.back();
        v.push_back(was * 2);
    }
    vector<ll> temp;
    for(int i = 0; i < n; i++) {
        ll x;
        scanf("%I64d", &x);
        temp.push_back(x);
    }
    for(auto x: temp) {
        auto it = lower_bound(v.begin(), v.end(), x);
        if(it == v.end() || *it != x) {
            b[it - v.begin()]++;
        }
        else if(it != v.end() && *it == x) {
            c[it - v.begin()]++;
        }
    }
    vector<int> res;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < (int)v.size(); j++)
            a[j] = 0, d[j] = b[j];
        if(c[0] < i)
            continue;
        int open = i;
        for(int j = 0; j < (int)v.size(); j++) {
            open = min(open, c[j]);
            if(j > 0)
                a[j - 1] -= open;
            a[j] = open;
            b[j] += c[j] - open;
        }
        int cur = 0;
        bool ok = true;
        for(int j = 0; j < (int)v.size(); j++) {
            while(cur + 1 < j)
                cur++;
            cur--;
            while(cur + 1 < (int)v.size() && b[j] != 0) {
                cur++;
                int now = min(a[cur], b[j]);
                a[cur] -= now;
                b[j] -= now;
            }
            if(cur + 1 == (int)v.size()) {
                ok = false;
            }
        }
        if(ok)
            res.push_back(i);
        for(int j = 0; j < (int)v.size(); j++)
            b[j] = d[j];
    }
    sort(res.begin(), res.end());
    if(res.empty())
        cout << "-1\n";
    else {
        for(auto x: res)
            printf("%d ", x);
        printf("\n");
    }
    return 0;
}