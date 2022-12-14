#include <iostream>

using namespace std;

int main () {
    int sk, sb, st, hh1, hh2, mm1, mm2, hh3, mm3;
    char i, j;
    cin >> hh2 >> i >> mm2 >> hh1 >> j >> mm1;
    hh1 *= 60;
    hh2 *= 60;
    sk = hh1 + mm1;
    sb = hh2 + mm2;
    st = sb - sk;
    if (st < 0)
        st = 1440 + st;
    hh3 = st / 60;
    mm3 = st % 60;
    if (mm3 < 10 && hh3 >= 10)
        cout << hh3 << ":" << 0 << mm3;
    else if (hh3 < 10 && mm3 < 10)
        cout << 0 << hh3 << ":" << 0 << mm3;
    else if (hh3 < 10 && mm3 >= 10)
        cout << 0 << hh3 << ":" << mm3;
    else
        cout << hh3 << ":" << mm3;
}