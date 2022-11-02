#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
int a[maxn];
string s;
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    vector<int>b;
    for(int i = 1; i < n; i++) b.push_back(a[i] - a[i-1]);
    sort(b.begin(), b.end());
    cout << b[0] << " ";

     b.push_back(-1);
    for(int i = 0; i < b.size(); i++) {
        if(b[i] != b[0]) {
            cout << i << "\n";
            return;
        }
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