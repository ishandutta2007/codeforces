#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int)1e5 + 9;
 int a[MxN + 9];

bool f() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];


        {
            static int exists[MxN + 9];
            fill(exists, exists + n + 9, 0);
            for(int i = 0; i < n; ++i)
                exists[a[i]] = 1;
            for(int i = 1; i <= n; ++i)
                if(!exists[i]) {
                    return false;
                }

    }

    int mn = 1;
    while(n > 0) {
        int i = n - 1;
        while(a[i] != mn) {
            --i;
            if(a[i] + 1 != a[i+1])
                return false;
        }
        mn = a[n-1] + 1;
        n = i;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cout << (f() ? "Yes" : "No") << "\n";
    }
    return 0;
}