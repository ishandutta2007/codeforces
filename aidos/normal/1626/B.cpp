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
    int pos = -1;
    for(int i = 1; i < s.size(); i++) {
        int x = s[i] - '0';
        int y = s[i-1] - '0';
        if(x + y > 9) pos = i-1;
    }
    if(pos != -1) {
        int x = s[pos] - '0';
        int y = s[pos+1] - '0';
        s[pos] = (x + y) / 10 + '0';
        s[pos + 1] = (x + y) % 10 + '0';
        cout << s << "\n";
        return;
    }
    else {
        cout << int(s[0] - '0') + int(s[1] - '0');
        for(int i = 2; i < s.size(); i++) cout << s[i];
        cout << "\n";
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