#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n, m, k;
int a[maxn];
vector<int> x, y, z;
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] > 0) {
            x.emplace_back(i);
        } else if(a[i] < 0) {
            y.emplace_back(i);
        } else {
            z.emplace_back(i);
        }
    }
    while(z.size() > 1) {
        cout << "1 " << z.back() << " "<< z[0] << "\n";
        z.pop_back();
    }
    if(y.size() % 2 == 1) {
        int bad = 0;
        for(int i = 0; i < y.size(); i++) {
            if(a[y[i]] > a[y[bad]]) bad = i;
        }
        swap(y.back(), y[bad]);
        if(z.size() == 1) {
            cout << "1 " << y.back() << " " << z[0] << "\n";
        } else {
            cout << "2 " << y.back() << "\n";
        }
        y.pop_back();
    }
    if(x.size()==0 && y.size() == 0) {
        return;
    }
    if(z.size() == 1) {
        cout << "2 " << z[0] << "\n";
    }
    for(int i = 0; i<y.size(); i++) {
        x.emplace_back(y[i]);
    }
    for(int i = 1; i < x.size(); i++) {
        cout << "1 " << x[i] << " "<<x[0] << "\n";
    }
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