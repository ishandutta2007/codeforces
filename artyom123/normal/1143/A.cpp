#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int cnt1 = 0, cnt2 = 0;
    int n;
    cin >> n;
    vector <int> a(n);
    for (auto &c : a) {
        cin >> c;
        if (c == 0) {
            cnt1++;
        }
        else {
            cnt2++;
        }
    }
    int now1 = 0, now2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            now1++;
        }
        else {
            now2++;
        }
        if (now1 == cnt1 || now2 == cnt2) {
            cout << i + 1;
            return 0;
        }
    }
    return 0;
}