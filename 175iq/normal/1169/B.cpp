#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)
const int MOD = 1000000007;

int main() {
    IOS;
    int n, m;
    cin>>n>>m;
    std::vector<pair<int, int> > a(m);
    for(int i = 0; i < m; i++) cin >> a[i].first >> a[i].second;
    std::vector<int> temp;
    temp.pb(a[0].first);
    temp.pb(a[0].second);
    for(int i = 0; i < m; i++) {
        if(a[i].first == a[0].first || a[i].first == a[0].second || a[i].second == a[0].first || a[i].second == a[0].second) {
            continue;
        } else {
            temp.pb(a[i].first);
            temp.pb(a[i].second);
            break;
        }
    }
    if(temp.size() == 2) {
        cout << "YES\n";
        return 0;
    }
    for(int i = 0; i < 4; i++) {
        for(int j = i + 1; j < 4; j++) {
            int x = temp[i];
            int y = temp[j];
            int f = 1;
            for(int i = 0; i < m; i++) {
                if(a[i].first != x && a[i].first != y && a[i].second != x && a[i].second != y) {
                    f = 0;
                    break;
                }
            }
            if(f) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}