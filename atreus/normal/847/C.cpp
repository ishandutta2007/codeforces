#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 1000;
int dp[maxn], a[maxn];

int main() {
    long long n, k;
    cin >> n >> k;
    string s;
    long long a = 0, ans = 0;
    while (true){
        if (a + ans > k){
            s += ')';
            a --;
        }
        else {
            s += '(';
            ans += a;
            a ++;
        }
        if (ans >= k){
            for (int i = 0; i < a; i++)
                s += ')';
            break;
        }
        if (s.size() > 2 * n){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    if (ans == k){
        while ((2 * n) > s.size()){
            s += "()";
        }
        if (s.size() > 2 * n){
            cout << "Impossible" << endl;
            return 0;
        }
        cout << s << endl;
    }
    else
        cout << "Impossible" << endl;
    return 0;
}