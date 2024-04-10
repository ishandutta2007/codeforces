#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;

const ll mod = 998244353;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);                                
    #endif     

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <ll> c(n);
        for (auto &i : c) {
            cin >> i;
        }
        if (*min_element(all(c)) > 1) {
            cout << "No\n";
            continue;
        }
        int pos = -1;
        for (int i = 0; i < n; i++) {
            if (c[i] == 1) {
                pos = i;
                break;
            }
        }
        vector <int> b;
        for (int i = pos; i < n; i++) b.p_b(c[i]);
        for (int i = 0; i < pos; i++) b.p_b(c[i]);
        int bad = 2;
        bool flag1 = 1;
        for (int i = 1; i < n; i++, bad++) {
            if (b[i] > b[i - 1] + 1 || b[i] == 1) {
                flag1 = 0;
            }
        }        
        if (flag1) cout << "Yes\n";
        else cout << "No\n";
    }
    
    return 0;
}