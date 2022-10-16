#include <iostream>

using namespace std;

const int MAXN = 10, MAXINV = 25;
int p[MAXN], cnt[MAXINV], n;

void gen(int k) {
    if(!k) {
        int inv = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                inv += (p[i] > p[j]);
        cnt[inv]++;
        return;
    }
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++) {
            for(int l = 0; 2 * l < j - i + 1; l++)
                swap(p[i + l], p[j - l]);
            gen(k - 1);
            for(int l = 0; 2 * l < j - i + 1; l++)
                swap(p[i + l], p[j - l]);
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(20);
    int k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    gen(k);
    int ans = 0;
    for(int i = 0; i <= n * (n - 1) / 2; i++)
        ans += i * cnt[i];
    int den = 1;
    for(int i = 0; i < k; i++)
        den *= n * (n + 1) / 2;
    cout << (long double)ans / den << '\n';
    return 0;
}