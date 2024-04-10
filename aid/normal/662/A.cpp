#include <iostream>
#include <bitset>

using namespace std;

const int MAXN = 500 * 1000 + 5, MAXB = 60;
bitset<MAXN> a[MAXB];
char b[MAXB];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long s = 0;
    for(int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        s = (s ^ x);
        x = (x ^ y);
        for(int j = 0; j < MAXB; j++)
            a[j][i] = ((x >> (long long)j) & 1);
    }
    for(int i = 0; i < MAXB; i++)
        b[i] = ((s >> (long long)i) & 1);
    int row = 0, col = 0;
    while(row < MAXB && col < n) {
        while(col < n) {
            int row0 = -1;
            for(int i = row; i < MAXB; i++)
                if(a[i][col]) {
                    row0 = i;
                    break;
                }
            if(row0 != -1) {
                swap(a[row], a[row0]);
                swap(b[row], b[row0]);
                for(int i = row + 1; i < MAXB; i++) {
                    if(!a[i][col])
                        continue;
                    a[i] ^= a[row];
                    b[i] ^= b[row];
                }
                col++;
                break;
            }
            col++;
        }
        if(col < n)
            row++;
    }
    for(int i = row; i < MAXB; i++)
        if(b[i]) {
            cout << "1/1\n";
            return 0;
        }
    cout << (1ll << (long long)row) - 1 << "/" << (1ll << (long long)row) << '\n';
    return 0;
}