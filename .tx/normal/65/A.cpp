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

const string RON = "Ron";
const string HERMIONE = "Hermione";

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(a, b, c, d, e, f);
    
    int bdf = b * d * f;
    int ace = a * c * e;
    if (bdf != 0 && ace != 0) {
        if (bdf > ace) {
            cout << RON;
        } else {
            cout << HERMIONE; 
        }
        return 0;
    }
    
    if (d == 0) {
        cout << HERMIONE;
    } else if (c == 0) {
        cout << RON;
    } else if (b == 0) {
        cout << HERMIONE;
    } else if (a == 0) {
        cout << RON;
    } else if (f == 0) {
        cout << HERMIONE;
    } else {
        cout << RON; 
    }

    return 0;
}