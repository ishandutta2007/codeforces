#include <iostream>
#include <algorithm>
#include <complex>

#define lint long long int
using namespace std;

typedef complex <lint> Point;

const int MOD = 1000000000 + 7;
const int NMAX = 200 + 5;

int n;
Point points[NMAX];

lint dot(const Point &a, const Point &b) {
    return real(conj(a) * b);
}

lint cross(const Point &a, const Point &b) {
    return imag(conj(a) * b);
}

bool intersect(const Point &a, const Point &b, const Point &p, const Point &q)
{
    lint d1MinX = min(real(a), real(b));
    lint d1MaxX = max(real(a), real(b));
    lint d2MinX = min(real(p), real(q));
    lint d2MaxX = max(real(p), real(q));

    lint d1MinY = min(imag(a), imag(b));
    lint d1MaxY = max(imag(a), imag(b));
    lint d2MinY = min(imag(p), imag(q));
    lint d2MaxY = max(imag(p), imag(q));

    if (d1MinX > d2MaxX || d2MinX > d1MaxX)
        return false;
    if (d1MinY > d2MaxY || d2MinY > d1MaxY)
        return false;

    lint crossABP = cross(a - b, p - b);
    lint crossABQ = cross(a - b, q - b);

    if ((crossABP >= 0 && crossABQ <= 0) || (crossABP <= 0 && crossABQ >= 0)) {
        lint crossPQA = cross(p - q, a - q);
        lint crossPQB = cross(p - q, b - q);
        if ((crossPQA >= 0 && crossPQB <= 0) || (crossPQA <= 0 && crossPQB >= 0))
            return true;
        else
            return false;
    }
    else
        return false;
}

inline int urm(int x) {
    if (x == n)
        return 1;
    else
        return x + 1;
}

inline int ante(int x) {
    if (x == 1)
        return n;
    else
        return x - 1;
}

bool validDiag[NMAX][NMAX];

void computeValidDiag() {
    for (int i = 1; i <= n; ++ i)
        for (int j = i + 1; j <= n; ++ j) {
            validDiag[i][j] = true;
            for (int k = 1; k <= n; ++ k)
                if (k != i && k != ante(i) &&
                    k != j && k != ante(j))
                        if (intersect(points[i], points[j], points[k], points[urm(k)])) {
                            validDiag[i][j] = false;
                            break;
                        }

            for (int k = 1; k <= n; ++ k)
                if (k != i && k != j && intersect(points[i], points[j], points[k], points[k])) {
                    validDiag[i][j] = false;
                    break;
                }
            if (validDiag[i][j]) {
                //Need to check whether or not this diagonal is completely inside
                //or outside the polygon
                lint area = 0;
                for (int k = i; k < j; ++ k)
                    area += cross(points[k], points[k + 1]);
                area += cross(points[j], points[i]);
                if (area > 0)
                    validDiag[i][j] = false;

                area = 0;
                for (int k = 1; k < i; ++ k)
                    area += cross(points[k], points[urm(k)]);
                for (int k = j; k <= n; ++ k)
                    area += cross(points[k], points[urm(k)]);
                area += cross(points[i], points[j]);
                if (area > 0)
                    validDiag[i][j] = false;
            }
        }

    for (int i = 1; i < n; ++ i)
        validDiag[i][urm(i)] = true;
    validDiag[1][n] = true;

    //for (int i = 1; i <= n; ++ i)
    //    for (int j = 1; j <= n; ++ j)
    //        if (validDiag[i][j])
                //cout << i << ' ' << j << endl;
                //validDiag[j][i] = validDiag[i][j];
}

int dp[NMAX][NMAX];

void computeDp() {
    for (int i = n; i; -- i) {
        dp[i][i] = 1;
        if (i < n)
            dp[i][i + 1] = 1;

        for (int j = i + 2; j <= n; ++ j) {
            for (int k = i + 1; k < j; ++ k)
                if (validDiag[i][k] && validDiag[k][j])
                    dp[i][j] = (dp[i][j] + 1LL * dp[i][k] * dp[k][j]) % MOD;
        }
    }
}

int main()
{
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; ++ i) {
        int x, y;
        cin >> x >> y;
        points[i] = Point(x, y);
    }

    lint area = 0;
    for (int i = 1; i <= n; ++ i)
        area += cross(points[i], points[urm(i)]);
    if (area > 0)
        reverse(points + 1, points + n + 1);

    //for (int i = 1; i <= n; ++ i)
    //    cout << '(' << real(points[i]) << ", " << imag(points[i]) << ")" << endl;


    computeValidDiag();
    computeDp();

    cout << dp[1][n] << '\n';
    return 0;
}