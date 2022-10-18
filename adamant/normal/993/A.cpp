#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;

typedef int ftype;
typedef complex<ftype> point;
#define x real
#define y imag

ftype dot(point a, point b) {
    return (conj(a) * b).x();
}
ftype cross(point a, point b) {
    return (conj(a) * b).y();
}
bool inside(point a, point b, point c, point d, point s) {
    return abs(cross(s - a, s - b)) + abs(cross(s - b, s - c)) + abs(cross(s - c, s - d)) + abs(cross(s - d, s - a)) ==
            abs(cross(s - a, s - b) + cross(s - b, s - c) + cross(s - c, s - d) + cross(s - d, s - a));
}


int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    point r[2][4];
    for(int z = 0; z < 2; z++) {
        for(int i = 0; i < 4; i++) {
            int x, y;
            cin >> x >> y;
            r[z][i] = {x, y};
        }
    }
    for(int X = -200; X <= 200; X++) {
        for(int Y = -200; Y <= 200; Y++) {
            if(inside(r[0][0], r[0][1], r[0][2], r[0][3], {X, Y}) && inside(r[1][0], r[1][1], r[1][2], r[1][3], {X, Y})) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}