#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 3005;
int a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < m; i++)
        cin >> b[i];
    sort(b, b + m);
    int i = 0, j = 0;
    for(; i < n; i++) {
        while(j < m && b[j] < a[i])
            j++;
        if(j == m)
            break;
        j++;
    }
    cout << n - i << '\n';
    return 0;
}