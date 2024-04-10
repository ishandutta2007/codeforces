#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int N = 25000 + 5;

int n, a[20];

int main(){
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("a.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int maxC = (1<<n) - 1;
    int check = 0;
    int tot = 0;
    for (int i = 0; i< n; i++) tot += a[i];
    for (int i = 0; i < maxC; i++) {
        int tmp = 0;
        int ii = i;
        int id = 0;
        while (ii) {
            if (ii % 2 == 1) {
                tmp += a[id];
            }
            ii /= 2;
            id++;
        }
        if ((2 * tmp - tot) % 360 == 0) check = 1;
    }
    if (check) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}