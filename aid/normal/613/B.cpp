#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100 * 1000 + 5;
pair<int, int> a[MAXN];
long long s[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, maxa, cf, cm;
    long long m;
    cin >> n >> maxa >> cf >> cm >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    s[0] = 0;
    for(int i = 0; i < n; i++)
        s[i + 1] = s[i] + a[i].first;
    if((long long)n * maxa - s[n] <= m) {
        cout << n * cf + (long long)maxa * cm << '\n';
        for(int i = 0; i < n; i++)
            cout << maxa << ' ';
        cout << '\n';
        return 0;
    }
    long long ans = 0, sum = 0;
    for(int i = n, j = n - 1; i > 0 && sum <= m; i--) {
        long long mm = m - sum;
        j = min(j, i - 1);
        while((long long)j * a[j].first - s[j] > mm)
            j--;
        mm -= (long long)j * a[j].first - s[j];
        ans = max(ans, (n - i) * cf +
                  min(a[j].first + mm / (j + 1), (long long)maxa) * cm);
        sum += maxa - a[i - 1].first;
    }
    cout << ans << '\n';
    sum = 0;
    for(int i = n, j = n - 1; i > 0 && sum <= m; i--) {
        long long mm = m - sum;
        j = min(j, i - 1);
        while((long long)j * a[j].first - s[j] > mm)
            j--;
        mm -= (long long)j * a[j].first - s[j];
        if(ans == (n - i) * cf +
           min(a[j].first + mm / (j + 1), (long long)maxa) * cm) {
            int mina = min(a[j].first + mm / (j + 1), (long long)maxa);
            for(int k = 0; k <= j; k++)
                a[k].first = mina;
            for(int k = i; k < n; k++)
                a[k].first = maxa;
            for(int k = 0; k < n; k++)
                swap(a[k].first, a[k].second);
            sort(a, a + n);
            for(int k = 0; k < n; k++)
                cout << a[k].second << ' ';
            cout << '\n';
            return 0;
        }
        sum += maxa - a[i - 1].first;
    }
    return 0;
}