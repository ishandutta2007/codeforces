#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve() {
    string s;
    cin >> s;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                int d[] = {i, j, k};
                int bal = 0;
                int g = 0;
                for(char c: s) {
                    if(d[c-'A']) bal++;
                    else bal--;
                    if(bal < 0) g=1;
                }
                if(g == 0 && bal == 0) {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}