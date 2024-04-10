#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define ppi pair<int,pi>
#define MOD 1000000007

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> xs(n);
        for(int &x : xs) {
            cin >> x;
        }
        sort(xs.begin(), xs.end());
        ll sum1 = xs[0];
        ll sum2 = 0;
        int i = 1;
        int j = n - 1;
        while(i < j) {
            sum1 += xs[i++];
            sum2 += xs[j--];
        }
        cout << (sum2 > sum1 ? "YES\n" : "NO\n");
    }
    return 0;
}