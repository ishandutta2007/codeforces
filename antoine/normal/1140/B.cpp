#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int f() {

    int n;
    string s;
    cin >> n>>s;
    string t = s;
    reverse(t.begin(), t.end());

    int i = s.find('>');
    int j = t.find('<');
    return min(i==-1?n:i, j==-1?n:j);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cout << f() << endl;
    }
    return 0;
}