#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define ld long double
#define f first
#define s second

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> xs(n);
    for(int i = 0; i < n; i ++) {
        cin >> xs[i];
    }
    int res = xs[n-1];
    if(k < n) {
        int dif = n - k;
        for(int i = 0; i < dif; i ++) {
            res = max(res,xs[i]+xs[2*dif-1-i]);
        }
    }
    cout << res;
}