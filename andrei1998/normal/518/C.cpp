#include <iostream>
#include <algorithm>

using namespace std;

int perm[100005];
int pos[100005];

inline void inv (int a, int b) {
    if (a == b)
        return ;

    int x = perm[a];
    int y = perm[b];

    swap(perm[a], perm[b]);
    swap(pos[x], pos[y]);
}

inline int gst (int a, int k) {
    return (1 + (a - 1) / k);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> perm[i];
        pos[perm[i]] = i;
    }

    int shp;
    long long int ans = 0;

    while (m--) {
        cin >> shp;

        ans += gst(pos[shp], k);

        inv(pos[shp], max(pos[shp] - 1, 1));
    }

    cout << ans << '\n';
    return 0;
}