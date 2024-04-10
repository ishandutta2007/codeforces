#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];
void solve(){
    string s, t;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int it = 0; it < 100; it++) {
        random_shuffle(a, a + n);
        int s = 0;
        int bad = 0;
        for(int j = 0; j < n; j++) {
            s += a[j];
            if(s == k) bad = 1;
        }
        if(!bad) {
            cout << "YES\n";
            for(int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << "\n";
            return;
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