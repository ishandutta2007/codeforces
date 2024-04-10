#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
int dij[100000];

int findd (int a) {
    if (a == dij[a]) return a;
    return dij[a] = findd(dij[a]);
}

int main () {
    int n, m, a, b;
    cin >> n >> m;
    pii nums[m];
    fop (i,0,m) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        nums[i] = mp(a-1, b-1);
    }
    fop (i,0,n) dij[i] = i;
    sort(nums, nums + m);
    int ans = 0;
    fop (i,0,m) {
        tie(a, b) = nums[i];
        if (findd(a) == findd(b)) {
            ans++;
            continue;
        }
        dij[findd(a)] = findd(b);
    }
    cout << ans << endl;
}