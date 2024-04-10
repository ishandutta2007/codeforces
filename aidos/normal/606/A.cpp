#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
int a[maxn];
int b[maxn];
void solve() {
    for(int i = 0; i < 3; i++) cin >> a[i];
    for(int i = 0; i < 3; i++) cin >> b[i];
    int s1 = 0, s2 = 0;
    for(int i = 0; i < 3; i++) {
        if(a[i] < b[i]) s2 += b[i] - a[i];
        else s1 += (a[i] - b[i])/2;
    }
    if(s1 >= s2) {
        cout << "Yes\n";
    }else {
        cout << "No\n";
    }
}


int main() {
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