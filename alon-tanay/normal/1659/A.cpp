#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define MOD 998244353
#define pi pair<int,int>
#define f first
#define s second

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, r, b;
        cin >> n >> r >> b;
        int ans = (r+b) / (b+1);
        int idx = 0;
        int A = r - (ans-1)*(b+1);
        for(int bi = 0; bi < min(A,b); bi ++) {
            for(int i = 0; i < ans; i ++) {
                cout << "R";
            }
            cout << "B";
        }
        for(int bi = A; bi < b; bi ++) {
            for(int i = 1; i < ans; i ++) {
                cout << "R";
            }
            cout << "B";
        }
        if(A == b+1) {
            cout << "R";
        }
        for(int i = 1; i < ans; i ++) {
            cout << "R";
        }
        cout << "\n";
    }
    return 0;
}