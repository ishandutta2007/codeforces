#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 500 * 1000 + 5;
int s[MAXN];
char used[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    sort(s, s + n);
    int j = 1, ans = n, last = 1;
    for(int i = 0; i < n; i++) {
        if(last < i) {
            last = i;
            while(last < n && used[last])
                last++;
            if(last >= n)
                break;
        }
        if(used[i]) {
            used[last] = true;
            last++;
            while(last < n && used[last])
                last++;
            if(last >= n)
                break;
        }
        j = max(j, last);
        while(j < n && (s[j] < 2 * s[i] || used[j]))
            j++;
        if(j >= n)
            break;
        used[j] = true;
        if(last == j)
            last++;
        j++;
        ans--;
    }
    cout << ans << '\n';
    return 0;
}