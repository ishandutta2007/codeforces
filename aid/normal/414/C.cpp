#include <iostream>
#include <map>

using namespace std;

const int MAXN = 25, POWN = 2000 * 2000 + 5;
int a[POWN], b[POWN], q[POWN];
long long ans[POWN];
pair<long long, long long> inv[MAXN];

void mergeSort(int l, int n, int a[], int b[]) {
    if(n == 0)
        return;
    int m = l + (1 << (n - 1)), r = l + (1 << n);
    mergeSort(l, n - 1, b, a);
    mergeSort(m, n - 1, b, a);
    int i = l, j = m, k = l, f = j;
    while(i < m && j < r)
        if(a[i] <= a[j]) {
            b[k] = a[i];
            if(f < j)
                f = j;
            while(f < r && a[i] == a[f])
                f++;
            inv[n].second += r - f;
            i++;
            k++;
        }
        else {
            b[k] = a[j];
            inv[n].first += m - i;
            j++;
            k++;
        }
    while(i < m) {
        b[k] = a[i];
        i++;
        k++;
    }
    while(j < r) {
        b[k] = a[j];
        j++;
        k++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < (1 << n); i++)
        cin >> a[i];
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> q[i];
    for(int i = 0; i < (1 << n); i++)
        b[i] = a[i];
    mergeSort(0, n, a, b);
    for(int i = 1; i <= n; i++) {
        inv[i].first += inv[i - 1].first;
        inv[i].second += inv[i - 1].second;
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j <= q[i]; j++)
            swap(inv[j].first, inv[j].second);
        for(int j = q[i] + 1; j <= n; j++) {
            inv[j].first += inv[q[i]].first - inv[q[i]].second;
            inv[j].second -= inv[q[i]].first - inv[q[i]].second;
        }
        ans[i] = inv[n].first;
    }
    for(int i = 0; i < m; i++)
        cout << ans[i] << '\n';
    return 0;
}