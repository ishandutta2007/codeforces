#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 1000 * 1000 + 5;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    n++;
    for(int i = 0; i < n; i++)
        a[i] = i;
    for(int k = 1; k < n; k *= 2) {
        for(int i = 0; i < n; i += 2 * k) {
            for(int j = 0; j < k; j++) {
                if(i + k + j >= n)
                    break;
                swap(a[i + j], a[i + k + j]);
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++)
        ans += (i ^ a[i]);
    cout << ans << '\n';
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';
    return 0;
}