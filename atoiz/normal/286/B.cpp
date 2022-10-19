#include <cstdio>
#include <algorithm>
#include <numeric>

using namespace std;

const int N = (1 << 21);
int a[N];

int main()
{
    int n; scanf("%d", &n);
    iota(a + 2, a + n + 2, 1);
    for (int k = 2; k <= n; ++k) {
        int last = 0;
        for (int i = k; i < n + k; i += k) {
            swap(last, a[i]);
        }
        swap(last, a[n + k]);
    }
    for (int i = n + 1; i <= 2 * n; ++i) printf("%d ", a[i]);
}