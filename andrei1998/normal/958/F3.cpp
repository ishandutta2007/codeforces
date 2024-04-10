#include <bits/stdc++.h>

using namespace std;

namespace fft {
    const long double PI = acosl(-1.0L);
    const int BITSMAX = 20;
    const int NMAX    = (1 << BITSMAX);

    struct Point {
        long double x, y;
        Point(): x(0), y(0) {}
        explicit Point(long double _x, long double _y): x(_x), y(_y) {}
        explicit Point(long double theta): x(cos(theta)), y(sin(theta)) {}
        Point operator+(const Point &arg) const { return Point(x + arg.x, y + arg.y); }
        Point operator-(const Point &arg) const { return Point(x - arg.x, y - arg.y); }
        Point operator*(const Point &arg) const { return Point(x * arg.x - y * arg.y, x * arg.y + y * arg.x); }
        Point operator/(const int &arg) const { return Point(x / arg, y / arg); }
        friend inline Point conj(const Point &arg) { return Point(arg.x, -arg.y); }
    };
    ostream& operator<<(ostream &g, const Point &p) {
        g << '(' << p.x << ',' << p.y << ')';
        return g;
    }
    Point w[2][2 * NMAX];
    void precomputeRoots() {
        w[0][1] = w[1][1] = Point(1, 0);
        for (int k = 1; k <= BITSMAX; ++ k) {
            Point W0(2.0 * PI / (1 << k));
            Point W1 = conj(W0);
            const int bound = (1 << k);
            for (int i = (1 << (k - 1)); i < bound; ++ i) {
                w[0][2 * i] = w[0][i], w[0][2 * i + 1] = w[0][i] * W0;
                w[1][2 * i] = w[1][i], w[1][2 * i + 1] = w[1][i] * W1;
            }
        }
    }

    int rev[NMAX];
    void fft(Point v[], const int BITS, const bool inv = false) {
        static bool computed = false;
        if (!computed)
            precomputeRoots(), computed = true;
        const int N = (1 << BITS);
        for (int i = 1; i < N; ++ i) {
            rev[i] = rev[i >> 1] >> 1;
            if (i & 1)
                rev[i] += N / 2;
        }
        for (int i = 0; i < N; ++ i)
            if (i < rev[i])
                swap(v[i], v[rev[i]]);
        for (int len = 1; len < N; len <<= 1) {
            double theta = PI / len;
            if (inv) theta *= (-1);
            for (int start = 0; start < N; start += 2 * len) {
                for (int i = 0; i < len; ++ i) {
                    const Point b = v[start + i + len] * w[inv][2 * len + i];
                    v[start + i + len] = v[start + i] - b;
                    v[start + i] = v[start + i] + b;
                }
            }
        }
        if (inv)
            for (int i = 0; i < N; ++ i)
                v[i] = v[i] / N;
    }

    Point points[NMAX], pointsA[NMAX], pointsB[NMAX], pointsRes[NMAX];
    void convolute(const vector <int> &a, int Na, const vector <int> &b, int Nb, vector <int> &res) {
        /*if (Na * Nb <= 16 * 16) {
            for (int i = 0; i < Na + Nb - 1; ++ i)
                res[i] = 0;
            for (int i = 0; i < Na; ++ i)
                for (int j = 0; j < Nb; ++ j)
                    res[i + j] += a[i] * b[j];
            for (int i = 0; i < Na + Nb - 1; ++ i)
                res[i] %= 1009;
            return ;
        }*/

        int BITS = 0;
        while ((1 << BITS) < Na + Nb - 1) ++ BITS;
        const int N = (1 << BITS);

        for (int i = 0; i < Na; ++ i)
            points[i] = Point(a[i], 0);
        for (int i = Na; i < N; ++ i)
            points[i] = Point();
        for (int i = 0; i < Nb; ++ i)
            points[i] = Point(points[i].x, b[i]);

        fft(points, BITS);

        for (int i = 0; i < N; ++ i) {
            const Point &A = points[i];
            const Point &B = conj(points[(N - i) & (N - 1)]);
            pointsA[i] = (A + B) * Point(0.5, 0);
            pointsB[i] = (A - B) * Point(0, -0.5);
        }

        for (int i = 0; i < N; ++ i)
            pointsRes[i] = pointsA[i] * pointsB[i];

        fft(pointsRes, BITS, true);
        for (int i = 0; i < res.size(); ++ i)
            res[i] = ((long long int)(pointsRes[i].x + 0.5)) % 1009;
    }
};

const int NMAX = 200000 + 5;

int N, M, K;
map <int, int> Map;

struct Poly {
    vector <int> poly;
    Poly(const vector <int> &_poly): poly(_poly) {}

    friend bool operator<(const Poly &a, const Poly &b) {
        return a.poly.size() > b.poly.size();
    }
    friend Poly operator+(const Poly &a, const Poly &b) {
        vector <int> v(a.poly.size() + b.poly.size() - 1);
        fft :: convolute(a.poly, a.poly.size(), b.poly, b.poly.size(), v);
        return Poly(v);
    }
};

priority_queue <Poly> pq;

int main() {
    ios_base :: sync_with_stdio(false);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++ i) {
        int val;
        cin >> val;
        ++ Map[val];
    }

    for (auto it: Map) {
        int cnt = it.second;
        vector <int> v(cnt + 1, 1);
        pq.push(Poly(v));
    }

    while (pq.size() > 1) {
        const Poly a = pq.top(); pq.pop();
        const Poly b = pq.top(); pq.pop();
        pq.push(a + b);
    }

    cout << pq.top().poly[K] << '\n';
    return 0;
}