#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, a[MAXN];
vector<int> written[MAXN];
int last[MAXN];

int main() {
    #ifdef Fekete
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else

    #endif // Fekete

//    ios::sync_with_stdio(false);
  //  cin.tie(nullptr);


    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n; i++) {
        int l = 0, r = MAXN - 1;
        while(l < r) {
            int m = (l + r) / 2;
            if(last[m] < a[i]) {
                r = m;
            }
            else {
                l = (m + 1);
            }
        }
        written[l].push_back(a[i]);
        last[l] = a[i];
    }
    for(int i = 0; last[i] > 0; i++) {
        for(auto x : written[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }
}