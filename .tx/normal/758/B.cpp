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

char ans[255];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scids(s);
    char a[4];
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] != '!') {
            a[i % 4] = s[i];
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '!') {
            ans[a[i % 4]]++;
        }
    }
    
    printf("%d %d %d %d", ans['R'], ans['B'], ans['Y'], ans['G']);
    

    return 0;
}