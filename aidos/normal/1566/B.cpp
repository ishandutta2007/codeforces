#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve(){
    string s;
    cin >> s;
    int cnta = 0;
    int cntb = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '0') cnta++;
        if(s[i] == '1') cntb++;
    }
    if(cnta > 0) {
        if(cntb > 0) {
            int i = 0;
            while(s[i] == '1') i++;
            int j = s.size() - 1;
            while(s[j] == '1') j--;
            while(s[i] == '0') i++;
            if(i > j) cout << 1 << "\n";
            else cout << 2 << "\n";
        } else {
            cout << 1 << "\n";
        }
    } else {
        cout << 0 << "\n";
    }
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}