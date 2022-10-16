#include <iostream>

using namespace std;

struct Point {
    int x, y;

    Point() {}

    Point(int _x, int _y): x(_x), y(_y) {}

    Point operator+(const Point &p) const {
        return Point(x + p.x, y + p.y);
    }
    
    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }

    bool operator==(const Point &p) const {
        return x == p.x && y == p.y;
    }
};

const int N = 8;
Point p[N];

int sp(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

bool isSquare(int a, int b, int c, int d) {
    for(int i = 0; i < 3; i++) {
        if(sp(p[b] - p[a], p[c] - p[a]) == 0 &&
           sp(p[b] - p[a], p[b] - p[a]) == sp(p[c] - p[a], p[c] - p[a]) &&
           p[d] == p[a] + (p[b] - p[a]) + (p[c] - p[a]))
            return true;
        swap(b, c);
        swap(c, d);
    }
    return false;
}

bool isRect(int a, int b, int c, int d) {
    for(int i = 0; i < 3; i++) {
        if(sp(p[b] - p[a], p[c] - p[a]) == 0 &&
           p[d] == p[a] + (p[b] - p[a]) + (p[c] - p[a]))
            return true;
        swap(b, c);
        swap(c, d);
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < N; i++)
        cin >> p[i].x >> p[i].y;
    for(int i = 0; i < N; i++)
        for(int j = i + 1; j < N; j++)
            for(int k = j + 1; k < N; k++)
                for(int l = k + 1; l < N; l++) {
                    int a = 0;
                    while(a == i || a == j || a == k || a == l)
                        a++;
                    int b = a + 1;
                    while(b == i || b == j || b == k || b == l)
                        b++;
                    int c = b + 1;
                    while(c == i || c == j || c == k || c == l)
                        c++;
                    int d = c + 1;
                    while(d == i || d == j || d == k || d == l)
                        d++;
                    if(isSquare(i, j, k, l) && isRect(a, b, c, d)) {
                        cout << "YES\n" << i + 1 << ' ' << j + 1 << ' '
                             << k + 1 << ' ' << l + 1 << '\n'
                             << a + 1 << ' ' << b + 1 << ' '
                             << c + 1 << ' ' << d + 1 << '\n';
                        return 0;
                    }
                }
    cout << "NO\n";
    return 0;
}