#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

const int a[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int x; string s; cin >> x >> s >> s;
    if(s.back() == 'k') {
        x--;
        int ans = 0;
        for(int i = 0; i < 366; i++)
            if((i + 4) % 7 == x)
                ans++;
        cout << ans;
    } else {
        int ans = 0;
        for(int i = 0; i < 12; i++)
            if(a[i] >= x)
                ans++;
        cout << ans;
    }
}