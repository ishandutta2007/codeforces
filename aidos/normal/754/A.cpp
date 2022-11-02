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
void solve() {
    cin >> n;
    vector<int> pos;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] != 0) pos.push_back(i);
    }
    if(pos.size() == 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << pos.size() << "\n";
    int last = 0;
    for(int i = 0; i + 1 < pos.size(); i++) {
        cout << last + 1 << " "<<pos[i] + 1 << "\n";
        last = pos[i] + 1;
    }
    cout << last + 1 << " " << n << "\n";
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