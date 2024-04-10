#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i < n * 2; i += 2) {
        ans += i;
    }
    for (int i = 1; i < n * 2 - 2; i += 2) {
        ans += i;
    }
    cout << ans;
    return 0;
}