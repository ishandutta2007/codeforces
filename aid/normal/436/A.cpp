#include <iostream>

using namespace std;

const int MAXN = 2005;
int t[MAXN], h[MAXN], m[MAXN];
char used[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i++)
        cin >> t[i] >> h[i] >> m[i];
    int ans = 0, maxh = x;
    for(int i = 0; i < n; i++) {
        int maxm = -1;
        for(int j = 0; j < n; j++)
            if(!used[j] && t[j] == (i & 1) &&
               h[j] <= maxh && (maxm == -1 || m[maxm] < m[j]))
                maxm = j;
        if(maxm == -1)
            break;
        used[maxm] = true;
        ans++;
        maxh += m[maxm];
    }
    for(int i = 0; i < n; i++)
        used[i] = false;
    int ans0 = 0;
    maxh = x;
    for(int i = 1; i <= n; i++) {
        int maxm = -1;
        for(int j = 0; j < n; j++)
            if(!used[j] && t[j] == (i & 1) &&
               h[j] <= maxh && (maxm == -1 || m[maxm] < m[j]))
                maxm = j;
        if(maxm == -1)
            break;
        used[maxm] = true;
        ans0++;
        maxh += m[maxm];
    }
    cout << max(ans, ans0) << '\n';
    return 0;
}