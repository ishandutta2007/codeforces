#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int b = 0;
        int k = 0;
        for(int i = 0; i < n; ++i){
            if (s[i] == '(')
                    b++;
            else{
                if (b)
                    b--;
                else
                    k++;
            }
        }
        cout << k << "\n";
    }
    return 0;
}