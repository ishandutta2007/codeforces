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

string NORTH = "North";
string SOUTH = "South";
string WEST = "West";
string EAST = "East";

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int x = 0;
    scid(n);
    for (int i = 0; i < n; i++) {
        scid(t);
        scids(s);
        int d = 0;
        if (s == NORTH) {
            if (x >= 20000) {
                d = 1;
            } else {
                d = -1;
            }
        } else if (s == SOUTH) {
            if (x >= 20000) {
                d = -1;
            } else {
                d = 1;
            }
        }
        while (t-- > 0) {
            if (x == 0) {
                if (s != SOUTH) {
                    cout << "NO";
                    return 0;
                }
            } else if (x == 20000) {
                if (s != NORTH) {
                    cout << "NO";
                    return 0;
                }
            }
            x += d;
            x = ((x % 40000) + 40000) % 40000;
        }
    }
    
    if (x != 0) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    

    return 0;
}