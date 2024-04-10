#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int a[222222];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, k);
    int lst = -1;
    int cm = 0;
    vector<int> dd;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        if (a[i] < 0) {
            cm++;
            if (lst != -1) {
                dd.push_back(i - lst - 1);
            }
            lst = i;
        }
    }
    
    
    if (cm > k) {
        cout << -1;
        return 0;
    }
    
    if (cm == 0) {
        cout << 0;
        return 0;
    }
    int hf = k - cm;
    
    int ans = 2 * cm;
    
    sort(dd.begin(), dd.end());
    for (int i = 0; i < dd.size(); i++) {
        if (dd[i] <= hf) {
            hf -= dd[i];
            ans -= 2;
        }
    }
    
    if (n - lst - 1 <= hf) {
        ans--;
    }
    
    cout << ans;
    return 0;
}