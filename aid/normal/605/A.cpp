#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int p[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        p[x] = i;
    }
    int len = 0;
    for(int i = 0; i < n;) {
        int j = i + 1;
        while(j < n && p[j - 1] < p[j])
            j++;
        len = max(len, j - i);
        i = j;
    }
    cout << n - len << '\n';
    return 0;
}