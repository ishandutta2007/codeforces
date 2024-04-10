#include <bits/stdc++.h>

using namespace std;


int l[200], r[200], vis[200];

int main() {
    #ifdef Fekete
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else

    #endif // Fekete

//    ios::sync_with_stdio(false);
  //  cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    int pr = -1;
    for(int i = 1; i <= n; i++) {
        if(l[i] == 0 && !vis[i]) {
            int last = -1;
            for(int j = i; j > 0; j = r[j]) {
                vis[j] = true;
                if(r[j] == 0) {
                    last = j;
                }
            }
            if(pr != -1) {
                l[i] = pr;
                r[pr] = i;
            }
            pr = last;
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << l[i] << " " << r[i] << "\n";
    }

}