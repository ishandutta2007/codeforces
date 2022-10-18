#include <bits/stdc++.h>

using namespace std;

int a[1005];
int T[155][3];
int used[1005];

main(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int uk = 1, cnt = 0;
    for (int time = 0; time <= 151 * n + 10; ++time){
        for (int j = 1; j <= k; ++j){
            if (T[j][0] == T[j][1]){
                if (T[j][0] > 0){
                    cnt++;
                }
                if (uk <= n) T[j][0] = 1, T[j][1] = a[uk], T[j][2] = uk, uk++;
                else T[j][0] = -1, T[j][1] = -1;
            }
            else T[j][0] = T[j][0] + 1;
        }
        int round = (int)((100 * (double)cnt / (double)n + 0.5));
        for (int j = 1; j <= k; ++j){
            if (T[j][0] == round){
                used[T[j][2]] = 1;
            }
        }
    }
    int answ = 0;
    for (int i = 1; i <= n; ++i) if (used[i] != 0) answ++;
    cout << answ << '\n';
    return 0;
}