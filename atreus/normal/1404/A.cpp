#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 4e5 + 10;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();
    int tc;
    cin >> tc;
    while (tc --){
        int n, k;
        string s;
        cin >> n >> k >> s;
        bool found = 0;
        for (int i = n-1; i >= k; i--){
            if (s[i] != '?' and s[i-k] != '?' and s[i] != s[i-k])
                found = 1;
            if (s[i-k] == '?')
                s[i-k] = s[i];
        }
        int cnt = 0, b = 0;
        for (int i = 0; i < k; i++){
            if (s[i] == '1')
                cnt ++;
            else if (s[i] == '0')
                cnt --;
            else
                b++;
        }
        if (k%2 == 1)
            found = 1;
        if (abs(cnt) > b)
            found = 1;
        if (found)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}