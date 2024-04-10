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
        int n, k;
        cin >> n >> k;
        int D = k&1;
        vector<int> str(n);
        vector<int> change(n);
        for(int i = 0; i < n; i ++) {
            char ch;
            cin >> ch;
            if(ch == '1' ^ D) { str[i] = 1; }
        }
        int move = 0;
        for(int i = 0; i < n; i ++) {
            if(!str[i] && move < k) {
                change[i] = 1;
                move ++;
            }
        }
        change[n-1] += k-move;
        for(int i = 0; i < n; i ++) {
            cout << (str[i]^(change[i]&1));
        }
        cout << "\n";
        for(int d : change) {
            cout << d << " ";
        }
        cout << "\n";
    }
    return 0;
}