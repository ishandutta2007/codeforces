#include <cstdio>
#include <vector>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair

typedef double ldouble;

const int MAXN = 300;
const int MAXY = 1001;
const ldouble EPS = 1e-9;

vector < pair <ldouble, ldouble> > v[MAXN];
int n, k;

template <typename T> T abs(T x) { return x < 0? -x : x; }

void getabc(ldouble x1, ldouble y1, ldouble x2, ldouble y2, ldouble &a, ldouble &b, ldouble &c)
{
    a = y2 - y1;
    b = x1 - x2;
    c = -(a * x1 + b * y1);
}

ldouble sign(ldouble x1, ldouble y1, ldouble x2, ldouble y2, ldouble x3, ldouble y3, ldouble x4, ldouble y4)
{
    ldouble a, b, c;
    getabc(x1, y1, x2, y2, a, b, c);
    return (a * x3 + b * y3 + c) * (a * x4 + b * y4 + c);
}

ldouble add(vector < pair <ldouble, ldouble> > &v, ldouble x1, ldouble y1, ldouble x2, ldouble y2)
{
    vector < pair <ldouble, ldouble> > a;
    bool opened = false;
    //printf("\t%.3lf %.3lf %.3lf %.3lf\n", x1, y1, x2, y2);
    //printf("\n");
    for (size_t i = 0; i < v.size(); ++i) {
        //printf("\t%.3lf %.3lf\n", v[i].X, v[i].Y);
    }

    for (size_t i = 1; i < v.size(); ++i) {
        ldouble sf = sign(v[i - 1].X, v[i - 1].Y, v[i].X, v[i].Y, x1, y1, x2, y2);
        ldouble ss = sign(x1, y1, x2, y2, v[i - 1].X, v[i - 1].Y, v[i].X, v[i].Y);

        if (!opened) {
            a.pb(v[i - 1]);
        }

        if (sf < EPS && ss < EPS) {

            ldouble a1, b1, c1, a2, b2, c2;
            getabc(x1, y1, x2, y2, a1, b1, c1);
            getabc(v[i - 1].X, v[i - 1].Y, v[i].X, v[i].Y, a2, b2, c2);

            ldouble d = a1 * b2 - a2 * b1;
            if (abs(d) < EPS) {
                continue;
            }

            ldouble x = (b1 * c2 - b2 * c1) / d + 0;
            ldouble y = (a2 * c1 - a1 * c2) / d + 0;
            //printf("\t%d x %.3lf %.3lf\n", i, x, y);

            if (abs(x - v[i].X) < EPS && abs(y - v[i].Y) < EPS) {
                continue;
            }

            if (!(abs(x - v[i - 1].X) < EPS && abs(y - v[i - 1].Y) < EPS) || opened) {
                a.pb(mp(x, y));
            }
            opened = !opened;
        }
    }
    a.pb(v[v.size() - 1]);
    if (opened) {
        return 0;
    }

    ldouble res = 0;
    for (size_t i = 1; i < v.size(); ++i) {
        res -= (v[i].X - v[i - 1].X) * (v[i].Y + v[i - 1].Y);
    }

    v.swap(a);
    for (size_t i = 1; i < v.size(); ++i) {
        res += (v[i].X - v[i - 1].X) * (v[i].Y + v[i - 1].Y);
    }

    res /= 2;


    //printf("\n");
    for (size_t i = 0; i < v.size(); ++i) {
        //printf("\t%.3lf %.3lf\n", v[i].X, v[i].Y);
    }

    //printf("\t = %.3lf\n", res);

    return res;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; ++i) {
        v[i].pb(mp(0, MAXY));
        v[i].pb(mp(0, 0));
        v[i].pb(mp(1, 0));
        v[i].pb(mp(1, MAXY));
    }

    for (int i = 0; i < n; ++i) {
        int y[k + 1];
        for (int j = 0; j <= k; ++j)
            scanf("%d", &y[j]);
        ldouble ans = 0;
        for (int j = 0; j < k; ++j) {
            //printf("Step %d, %d:\n", i, j);
            ans += add(v[j], 0, y[j], 1, y[j + 1]);
        }
        printf("%.7lf\n", (double)ans);
    }
    return 0;
}