#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
int b[maxn];
int ask(int l, int r) {
    cout << "? " << l << " "<<r <<endl;
    int ans;
    cin>>ans;
    return ans;
}
void solve(){
    cin >> n;
    for(int i = 2; i <= n; i++){
        b[i] = ask(1, i);
    }
    int c = ask(2, 3);
    int x = (b[2] + b[3] - c)/2;
    cout << "! ";
    cout << x;
    for(int i = 2; i <= n; i++) {
        cout << " " << b[i]-x;
    }
    cout << endl;
}


int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
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