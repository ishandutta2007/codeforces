#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, a[MAXN];
long long ans1[MAXN], ans2[MAXN];
long long minH1[MAXN], minH2[MAXN];

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
    minH1[0] = a[0];
    for(int i = 1; i < n; i++){
        minH1[i] = max(minH1[i - 1] + 1, 1ll*a[i]);
        ans1[i] = ans1[i - 1] + minH1[i] - a[i];
    }
    minH2[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--){
        minH2[i] = max(minH2[i + 1] + 1, 1ll*a[i]);
        ans2[i] = ans2[i + 1] + minH2[i] - a[i];
    }
    long long ans = 1e18;
    for(int i = 0; i < n; i++) {
        //cerr << ans1[i] << " " << ans2[i] << endl;
        ans = min(ans, ans1[i] + ans2[i] - min(minH1[i], minH2[i]) + a[i]);
    }
    cout << ans;
}