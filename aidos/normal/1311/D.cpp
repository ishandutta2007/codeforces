#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int a, b, c;
void solve() {
    cin >> a >> b >> c;
    int ans = inf;
    pair <int, pii> d;
    for(int B = 1; B <= 30000; B++) {
        for(int x = 1; x * x <= B; x++) {
            if(B % x != 0) continue;
            int A = x;
            int C = (c + B - 1)/B * B;
            if(C > B && abs(C - B - c) < abs(C-c)) C -= B;
            if(ans>abs(a-A) + abs(b-B) + abs(c-C)) {
                ans = abs(a-A) + abs(b-B) + abs(c-C);
                d = make_pair(A, make_pair(B, C));
            }
            A = B/x;
            if(ans>abs(a-A) + abs(b-B) + abs(c-C)) {
                ans = abs(a-A) + abs(b-B) + abs(c-C);
                d = make_pair(A, make_pair(B, C));
            }
        }
    }
    cout << ans << "\n";
    cout << d.first << " "<<d.second.first << " " << d.second.second << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}