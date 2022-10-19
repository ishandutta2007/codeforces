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

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

#define prev prefefasd

ostream& operator<<(ostream& cerr, vector<ll> aux) {
    cerr << "[";
    for (auto e : aux) cerr << e << ' ';
    cerr << "]";
    return cerr;
}

const int maxN = 100011;

int n, i, prev;
int v[maxN];
int v1, v2;
int ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &v[i]);

    if (v[1] == 1) {
        prev = 1;
        v1 = 1;
    } else {
        prev = 2;
        v2 = 1;
    }

    for (i = 2; i <= n; i++) {
        if (v[i] == prev) {
            if (v[i] == 1) v1++;
            else           v2++;
            ans = max(ans, min(v1, v2));
        } else {
            if (v[i] == 1) {
                v1 = 1;
            } else {
                v2 = 1;
            }
        }

        prev = v[i];
        ans = max(ans, min(v1, v2));
    }

    cout << ans * 2;
    
    return 0;
}