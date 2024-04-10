#include <iostream>

using namespace std;

const int MAXN = 105;
char col[MAXN], num[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> col[i] >> num[i];
        col[i] = (col[i] == 'R'? 0 :
                  (col[i] == 'G'? 1 :
                   (col[i] == 'B'? 2 : (col[i] == 'Y'? 3 : 4))));
        num[i] = num[i] - '1';
    }
    int ans = 10;
    for(int mask = 0; mask < (1 << 10); mask++) {
        bool bad = false;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++)
                if(col[i] == col[j]) {
                    if(num[i] == num[j])
                        continue;
                    else if(!(mask & (1 << (5 + num[i]))) &&
                            !(mask & (1 << (5 + num[j])))) {
                        bad = true;
                        break;
                    }
                }
                else {
                    if(num[i] == num[j] &&
                       !(mask & (1 << col[i])) &&
                       !(mask & (1 << col[j]))) {
                        bad = true;
                        break;
                    }
                    else if(!(mask & (1 << (5 + num[i]))) &&
                            !(mask & (1 << (5 + num[j]))) &&
                            !(mask & (1 << col[i])) &&
                            !(mask & (1 << col[j]))) {
                        bad = true;
                        break;
                    }
                }
            if(bad)
                break;
        }
        if(!bad)
            ans = min(ans, __builtin_popcount(mask));
    }
    cout << ans << '\n';
    return 0;
}