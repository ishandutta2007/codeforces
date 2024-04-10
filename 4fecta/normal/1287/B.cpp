#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 1505, MK = 35;

int n, K;
char c;
string a[MN];
map<string, int> mp;

int main() {
    boost();

    cin >> n >> K;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            string req = "";
            bool dif = 0;
            for (int k = 0; k < K; k++) {
                if (a[i][k] == a[j][k]) {req += a[i][k]; continue;}
                dif = 1;
                if (a[i][k] == 'S' && a[j][k] == 'E') req += 'T';
                if (a[i][k] == 'E' && a[j][k] == 'S') req += 'T';
                if (a[i][k] == 'S' && a[j][k] == 'T') req += 'E';
                if (a[i][k] == 'T' && a[j][k] == 'S') req += 'E';
                if (a[i][k] == 'E' && a[j][k] == 'T') req += 'S';
                if (a[i][k] == 'T' && a[j][k] == 'E') req += 'S';
            }
            //printf("%s\n", req.c_str());
            if (mp.count(req)) {
                if (dif) ans += mp[req];
                else ans += mp[req];
            }
        }
        if (!mp.count(a[i])) mp[a[i]] = 1;
        else mp[a[i]]++;
    }
    printf("%lld\n", ans);

    return 0;
}