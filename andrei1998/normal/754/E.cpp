#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <complex>
#include <string>
#include <cmath>

using namespace std;

struct Point {
    double r, i;

    Point(double _r = 0, double _i = 0): r(_r), i(_i) {}

    inline double real() {
        return r;
    }
    inline double imag() {
        return i;
    }

    friend Point operator+(const Point &a, const Point &b) {
        return Point(a.r + b.r, a.i + b.i);
    }
    friend Point operator-(const Point &a, const Point &b) {
        return Point(a.r - b.r, a.i - b.i);
    }
    friend Point operator*(const Point &a, const Point &b) {
        return Point(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r);
    }
    friend Point operator/(const Point &a, const double &b) {
        return Point(a.r / b, a.i / b);
    }

    Point operator*=(const Point &p) {
        (*this) = (*this) * p;
        return (*this);
    }
    Point operator/=(const double &p) {
        (*this) = (*this) / p;
        return (*this);
    }

    static Point polar(double r, double theta) {
        return Point(r * cos(theta), r * sin(theta));
    }

    inline double abs() {
        return sqrt(r * r + i * i);
    }
};

const int BITS = 11;
const int N = 1 << BITS;
const double PI = acos(-1);
const double EPS = 1e-8;

int bitReversal[N];

void computeBitReversal() {
    for (int i = 1; i < N; ++ i) {
        bitReversal[i] = bitReversal[i >> 1] >> 1;
        if (i & 1)
            bitReversal[i] += (N / 2);
    }
}

//typedef complex <double> Point;

void fft(Point mat[N][N], int inv = 1) {
    for (int i = 0; i < N; ++ i)
        for (int j = 0; j < N; ++ j)
            if (bitReversal[i] < i || (bitReversal[i] == i && bitReversal[j] < j))
                swap(mat[i][j], mat[bitReversal[i]][bitReversal[j]]);

    for (int l = 2; l <= N; l <<= 1) {
        Point w = Point :: polar(1.0, 2 * inv * PI / l);
        for (int startI = 0; startI < N; startI += l) {
            for (int startJ = 0; startJ < N; startJ += l) {
                Point wI = 1;
                for (int i = 0; i < l / 2; ++ i, wI *= w) {
                    Point wJ = 1;
                    for (int j = 0; j < l / 2; ++ j, wJ *= w) {
                        Point &m00 = mat[startI + i][startJ + j];
                        Point a00 = m00;
                        Point &m01 = mat[startI + i][startJ + j + l / 2];
                        Point a01 = wJ * m01;
                        Point &m10 = mat[startI + i + l / 2][startJ + j];
                        Point a10 = wI * m10;
                        Point &m11 = mat[startI + i + l / 2][startJ + j + l / 2];
                        Point a11 = wI * wJ * m11;

                        m00 = a00 + a01 + a10 + a11;
                        m01 = a00 - a01 + a10 - a11;
                        m10 = a00 + a01 - a10 - a11;
                        m11 = a00 - a01 - a10 + a11;
                    }
                }
            }
        }
    }

    if (inv == -1)
        for (int i = 0; i < N; ++ i)
            for (int j = 0; j < N; ++ j)
                mat[i][j] /= N * N;
}

Point mat1[N][N];
Point mat2[N][N];
Point mat[N][N];

bool match[N][N];

void computeProd(int r, int c, int necc) {
    computeBitReversal();

    fft(mat1);
    fft(mat2);

    for (int i = 0; i < N; ++ i)
        for (int j = 0; j < N; ++ j)
            mat[i][j] = mat1[i][j] * mat2[i][j];

    fft(mat, -1);

    for (int i = 0; i + r - 1 < N; ++ i)
        for (int j = 0; j + c - 1 < N; ++ j)
            if ((mat[i + r - 1][j + c - 1] - Point(necc)).abs() < EPS)
                match[i][j] = true;
}

const int NMAX = 2 * 800 + 5;

int n, m;
string text[NMAX];

int r, c;
string pattern[NMAX];

Point sgm[27];

void prepareMats() {
    sgm[0] = 1;
    sgm[1] = Point :: polar(1.0, 2 * PI / 26.0);
    for (int i = 2; i <= 26; ++ i)
        sgm[i] = sgm[i - 1] * sgm[1];

    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j)
            if (text[i][j] != '?')
                mat1[i][j] = sgm[text[i][j] - 'a'];

    for (int i = 0; i < r; ++ i)
        for (int j = 0; j < c; ++ j)
            if (pattern[i][j] != '?')
                mat2[i][j] = sgm[26 - (pattern[i][j] - 'a')];
}

int main()
{
    ios_base :: sync_with_stdio(false);
    //freopen("data.in", "r", stdin);

    //Read texts and to reversals
    cin >> n >> m;

    int initN = n;
    int initM = m;

    for (int i = 0; i < n; ++ i) {
        cin >> text[i];

        //Double text until its lines are 800 characters long
        while (text[i].size() < 800)
            text[i] += text[i];
    }

    //Complete the text until it's 800 lines long
    for (int i = 0; i < 800; ++ i)
        text[n + i] = text[i];

    n = 800;
    m = text[0].size();

    int necc = 0;

    cin >> r >> c;
    for (int i = 0; i < r; ++ i) {
        cin >> pattern[i];
        for (auto it: pattern[i])
            necc += it != '?';
        reverse(pattern[i].begin(), pattern[i].end());
    }
    reverse(pattern, pattern + r);

    //Solve
    prepareMats();
    computeProd(r, c, necc);

    //Print
    for (int i = 0; i < initN; ++ i) {
        for (int j = 0; j < initM; ++ j)
            cout << match[i][j];
        cout << '\n';
    }
    return 0;
}