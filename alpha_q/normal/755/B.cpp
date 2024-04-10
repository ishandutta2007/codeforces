#include <bits/stdc++.h> 

using namespace std;

set <string> s;
int n, m;

int main (int argc, char const *argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n + m; ++i) {
        string x; 
        cin >> x;
        s.insert(x);
    }
    int z = s.size();
    int k = n + m - z;
    n -= k, m -= k, n += (k & 1);
    if (n > m) puts("YES");
    else puts("NO");
    return 0;
}