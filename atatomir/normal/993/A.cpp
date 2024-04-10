#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

struct point {
    ll x, y;

    void read() {
        cin >> x >> y;
    }

    point rot() {
        return (point){x - y, x + y};
    }
};

struct squ {
    point A, B, C, D;

    void read() {
        A.read();
        B.read();
        C.read();
        D.read();
    }

    bool in(point act) {
        ll min_x = min(min(A.x, B.x), min(C.x, D.x));
        ll max_x = max(max(A.x, B.x), max(C.x, D.x));
        ll min_y = min(min(A.y, B.y), min(C.y, D.y));
        ll max_y = max(max(A.y, B.y), max(C.y, D.y));

        return (min_x <= act.x && act.x <= max_x &&
                min_y <= act.y && act.y <= max_y);
    }
};

squ S1, S2;
point O;

void yes() {
    printf("YES");
    exit(0);
}

int main()
{
    //freopen("test.in","r",stdin);

    S1.read();
    S2.read();

    if (S1.in(S2.A)) yes();
    if (S1.in(S2.B)) yes();
    if (S1.in(S2.C)) yes();
    if (S1.in(S2.D)) yes();

    O = (point){(S2.A.x + S2.B.x + S2.C.x + S2.D.x) / 4, (S2.A.y + S2.B.y + S2.C.y + S2.D.y) / 4};
    if (S1.in(O)) yes();

    S2.A = S2.A.rot();
    S2.B = S2.B.rot();
    S2.C = S2.C.rot();
    S2.D = S2.D.rot();

    S1.A = S1.A.rot();
    S1.B = S1.B.rot();
    S1.C = S1.C.rot();
    S1.D = S1.D.rot();

    swap(S1, S2);

    if (S1.in(S2.A)) yes();
    if (S1.in(S2.B)) yes();
    if (S1.in(S2.C)) yes();
    if (S1.in(S2.D)) yes();

    O = (point){(S2.A.x + S2.B.x + S2.C.x + S2.D.x) / 4, (S2.A.y + S2.B.y + S2.C.y + S2.D.y) / 4};
    if (S1.in(O)) yes();

    printf("NO\n");

    return 0;
}