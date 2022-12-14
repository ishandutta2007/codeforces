#include <iostream>

using namespace std;

char Triangle(int a, int b, int c){
    char x;
    if (a + b > c && a + c > b && b + c > a)
        x = 'Y';
    else
        x = 'N';
    return x;
}

char SEGMENT(int a, int b, int c){
    char y;
    if (a + b == c || a + c == b || b + c == a)
        y = 'Y';
    else
        y = 'N';
    return y;
}

char IMPOSSIBLE(int a, int b, int c){
    char z;
    if (a + b < c || a + c < b || b + c < a)
        z = 'Y';
    return z;
}

int main () {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    char t1, t2, t3, t4, s1, s2, s3, s4, i1, i2, i3, i4;
    t1 = Triangle(a, b, c);
    t2 = Triangle(a, b, d);
    t3 = Triangle(a, c, d);
    t4 = Triangle(b, c, d);
    s1 = SEGMENT(a, b, c);
    s2 = SEGMENT(a, b, d);
    s3 = SEGMENT(a, c, d);
    s4 = SEGMENT(b, c, d);
    i1 = IMPOSSIBLE(a, b, c);
    i2 = IMPOSSIBLE(a, b, d);
    i3 = IMPOSSIBLE(a, c, d);
    i4 = IMPOSSIBLE(b, c, d);
    if (t1 == 'Y' || t2 == 'Y' || t3 == 'Y' || t4 == 'Y')
        cout << "TRIANGLE" << endl;
    else if (s1 == 'Y' || s2 == 'Y' || s3 == 'Y' || s4 == 'Y')
        cout << "SEGMENT" << endl;
    else
        cout << "IMPOSSIBLE" << endl;
}