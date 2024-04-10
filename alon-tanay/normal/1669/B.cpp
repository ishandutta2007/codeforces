#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define MOD 998244353
#define pi pair<int,int>
#define pl pair<ll,ll>
#define f first
#define s second

using namespace std;

int cnt[200005];

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
            cnt[x] ++;
        }
        bool fail = true;
        for(int x : xs) {
            if(cnt[x] >= 3) {
                cout << x << "\n";
                fail = false;
                break;
            }
        }
        if(fail) {
            cout << "-1\n";
        }
        for(int x : xs) {
            cnt[x]--;
        }
    }
    return 0;
}