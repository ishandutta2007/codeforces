#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = 0;
    }
    vector<int> d, c;
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        if(d.size() == a[i]) {
            d.push_back(a[i]);
        } else c.push_back(a[i]);
    }
    for(int x: d){
        cout << x << " ";
    }

    for(int x: c){
        cout << x << " ";
    }
    cout << "\n";
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