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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    if (n == 3) {
        cout << "1\n3";
        return 0;
    }
    vector<int> ans;
    while (n > 0) {
        if (n == 5) {
            ans.push_back(2);
            ans.push_back(3);
            n = 0;
        } else {
            ans.push_back(2);
            n -= 2;
        }
    }
    
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }

    return 0;
}