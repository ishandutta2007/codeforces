#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
int a[maxn];
string s;
int ok[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    vector<int> x = {a[0]};
    for(int j = 0; j < 31; j++) {
        int l = 0;
        for (int i = 0; i < n; i++) {
            while(a[i] - a[l] > (1<<j)) l++;

            if(a[i] - a[l] == (1<<j)) {
                if(ok[l]) {
                    cout << 3 << "\n";
                    cout << a[i] - (1<<j) << " "<<a[i] << " "<<a[i] - 2*(1<<j) << "\n";
                    return;
                }
                x = {a[i] - (1<<j), a[i]};
                ok[i] = 1;
            }
            else ok[i] = 0;
        }
    }
    cout << x.size() << "\n";
    for(int v: x) {
        cout << v << " ";
    }
}

int main() {
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}