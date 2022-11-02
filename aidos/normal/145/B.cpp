#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
string s;
void calc(char c1, char c2, int a3, int a4, int a1, int a2) {
    string ans = "";
    while(a3 > 0 || a4 > 0) {
        if(ans.size() % 2 == 0) {
            if(ans.size() > 0) a4--;
            ans += c1;
            a1--;
        } else {
            if(ans.size() > 0) a3--;
            ans += c2;
            a2--;
        }
    }
    if(a3 < 0 || a4 < 0 || a1 < 0 || a2 < 0) return;
    string cur = "";
    if(c1 > c2) {
        swap(c1, c2);
        swap(a1, a2);
    }
    int pos = 0;
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] == c1 && a1 > 0) {
            while(a1> 0) {
                cur += c1;
                a1--;
            }
        }
        if(ans[i] == c2) pos = cur.size();
        cur += ans[i];
    }
    for(int i = 0; i < cur.size(); i++) {
        cout << cur[i];
        if(i == pos && a2 > 0) {
            while(a2 > 0) {
                cout << c2;
                a2--;
            }
        }
    }

    exit(0);
}
void solve() {
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    calc('4', '7', a3, a4, a1, a2);
    calc('7', '4', a4, a3, a2, a1);
    cout << -1 << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}