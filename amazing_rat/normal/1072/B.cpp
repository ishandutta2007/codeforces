#include <bits/stdc++.h>

using namespace std;

#define maxn 100010

int n, t[maxn], a[maxn], b[maxn];

bool solve() {
    for (int i = 1; i < n - 1; i++) {
        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            if ((t[i]|j) == a[i] && (t[i]&j) == b[i]) {
                t[i + 1] = j;
                ++cnt;
            }
        }
        if (cnt == 0) return false;
    }
    cout << "YES" << endl ;;
    for (int i = 0; i < n; i++) {
        cout << t[i] << " ";
    }
    return true;
}

int main(){
    
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if ((i|j) == a[0] && (i&j) == b[0]) {
                t[0] = i; 
                t[1] = j;
                bool res = solve();
                if (res) return 0;
            }
        }
    }
    cout << "NO" << endl ;
}