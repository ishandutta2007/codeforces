#include <iostream>

using namespace std;

const int MAXN = 1000 * 1000 + 5;
int a[MAXN], cnt[MAXN], cntDiv[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] <= m)
            cnt[a[i]]++;
    }
    for(int i = 1; i <= m; i++)
        for(int j = i; j <= m; j += i)
            cntDiv[j] += cnt[i];
    int l = 1;
    for(int i = 2; i <= m; i++)
        if(cntDiv[i] > cntDiv[l])
            l = i;
    cout << l << ' ' << cntDiv[l] << '\n';
    for(int i = 0; i < n; i++)
        if(!(l % a[i]))
            cout << i + 1 << ' ';
    cout << '\n';
    return 0;
}