#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve(){
    string s, t, a, b, c, d;
    cin >> s >> t;
    for(char x: s) {
        if(x == 'a') a += 'a';
        else if(x == 'b') b += 'b';
        else if(x == 'c') c += 'c';
        else d += x;
    }
    sort(d.begin(), d.end());
    if(t != "abc" || (a.size() == 0 || b.size() == 0 || c.size() == 0)) {
        cout << a + b + c + d << "\n";
    } else {
        cout << a + c + b + d<< "\n";
    }
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