#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef double ld;

const ld eps = 1e-12;

bool eq(ld a, ld b)
{
    return abs(a - b) <= eps;
}

bool gt(ld a, ld b)
{
    return a - b > eps;
}

bool lt(ld a, ld b)
{
    return b - a > eps;
}

bool geq(ld a, ld b)
{
    return gt(a, b) || eq(a, b);
}

ld mysqrt(ld val)
{
    if (lt(val, eps)) {
        val = 0;
    }
    return sqrt(val);
}

vector<ld> solve_eq(ld a, ld b, ld c)
{
    ld d2 = b * b - 4 * a * c;
    /*if (!geq(d2, 0)) {
        cout << "VERY BAD\n";
    }*/
    ld d = mysqrt(d2);
    //cout << "!!" << d << " " << d2 << "\n";
    vector<ld> v = {(-b - d) / 2 / a, (-b + d) / 2 / a};
    return v;
}

int main()
{

    //ifstream cin("input.txt");

    //ios_base::sync_with_stdio(false);
    int n;
    //cin >> n;
    scanf("%d", &n);

    vector<ld> M(n + 1), m(n + 1), s(n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf", &M[i]);
        //cin >> M[i];
    }
    for (int i = 1; i <= n; ++i) {
        //cin >> m[i];
        scanf("%lf", &m[i]);
        s[i] = M[i] + m[i];
    }

    vector<ld> c(n + 1), d(n + 1);
    for (int i = 1; i <= n; ++i) {
        c[i] = c[i - 1] + M[i];
        d[i] = d[i - 1] + s[i];
    }

    vector<ld> A(n + 1), B(n + 1);
    for (int i = 1; i <= n; ++i) {
        vector<ld> v = solve_eq(-1, d[i], -c[i]);
        sort(all(v));
        //cout << v[0] << " " << v[1] << "\n";
        A[i] = v[0], B[i] = v[1];
    }

    for (int i = 1; i <= n; ++i) {
        ld a = A[i] - A[i - 1];
        printf("%.12f ", a);
        //cout << a << " ";
    }
    printf("\n");
    for (int i = 1; i <= n; ++i) {
        ld b = B[i] - B[i - 1];
        printf("%.12f ", b);
        //cout << b << " ";
    }
    printf("\n");

}