#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

void solve() {
    int n;
    cin >> n;
    
    // n * (n - 1) / 2 = x
    string answer = "";
    if (n == 0) answer += "a";
    
    int letter = 0;
    while (n > 0) {
        li x = 1;
        while (x * (x - 1) / 2 <= n) {
            x++;
        }
        x--;
        
        n -= x * (x - 1) / 2;
        for (int i = 0; i < x; i++) answer += 'a' + letter;
        letter++;
    }
    
    cout << answer << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}