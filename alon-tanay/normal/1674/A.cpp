#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define vi vector<int>
#define INF 1073741823

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        if(y%x) {
            cout << "0 0\n";
            continue;
        }
        cout << "1 " << y/x << "\n";
    }
    return 0;
}