#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  //  freopen("in.txt", "r", stdin);
    int n; cin >> n;
    multiset<int> in;
    for(int i = 0; i < n * n; i++) {
        int x; cin >> x; in.insert(x);
    }
    vector<int> a;
    for(int i = 0; i < n; i++) {
        int x = *in.rbegin();
        in.erase(--in.end());
        for(int y : a) {
            in.erase(in.find(__gcd(x, y)));
            in.erase(in.find(__gcd(x, y)));
        }
        a.push_back(x);
    }
    for(int x : a) cout << x << ' ';
}