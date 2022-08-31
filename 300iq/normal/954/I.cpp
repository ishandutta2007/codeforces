#include <cmath>
#include <complex>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>
#define plus abacaba_plus
#define minus abacaba_minus
#define PI 3.141592653589793238462643383279

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int base = 1e5;
const int digits = 5;

struct big
{
    vector <int> num; 
    int sign;
};

bool operator < (const big &a, const big &b)
{
    if (a.num.size() != b.num.size())
    {
        return a.num.size() < b.num.size();
    }
    else
    {
        return a.num < b.num;
    }
}

bool operator > (const big &a, const big &b)
{
    if (a.num.size() != b.num.size())
    {
        return a.num.size() > b.num.size();
    }
    else
    {
        return a.num > b.num;
    }
}

struct my_complex
{
    long double real, imag;
    my_complex(long double a, long double b): real(a), imag(b)
    {
    }
    my_complex()
    {
    }
};

my_complex operator * (const my_complex &a, const my_complex &b)
{
    return {a.real * b.real - a.imag * b.imag, a.imag * b.real + a.real * b.imag};
}

my_complex operator - (const my_complex &a, const my_complex &b)
{
    return {a.real - b.real, a.imag - b.imag};
}

my_complex operator + (const my_complex &a, const my_complex &b)
{
    return {a.real + b.real, a.imag + b.imag};
}

typedef my_complex bse;

bse w[(int) 5e6];
 
void fft (vector<bse> & a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
    int it = 0;
	for (int len=2; len<=n; len<<=1) {
		for (int i=0; i<n; i+=len) {
            int jt = it;
			for (int j=0; j<len/2; ++j) {
				bse u = a[i+j],  v = a[i+j+len/2] * w[jt];
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
                jt++;
			}
		}
        it += len / 2;
	}
	if (invert)
    {
        reverse(a.begin() + 1, a.begin() + n);
        for (int i = 0; i < n; i++)
        {
            a[i].imag /= n;
        }
    }
}

vector <bse> fa, fb;

bool newton = false;

void multiply (const vector<int> & a, const vector<int> & b, vector<ll> & res) {
	size_t n = 1;
	while (n < a.size() + b.size())  n <<= 1;
	fa.resize (n);
    for (int i = 0; i < n; i++)
    {
        if (i < a.size() && i < b.size())
        {
            fa[i] = bse(a[i], b[i]);
        }
        else if (i < a.size())
        {
            fa[i] = bse(a[i], 0);
        }
        else if (i < b.size())
        {
            fa[i] = bse(0, b[i]);
        }
        else
        {
            fa[i] = bse(0, 0);
        }
    }
    fft(fa, false);
	for (size_t i=0; i<n; ++i)
		fa[i] = fa[i] * fa[i];
	fft (fa, true);
    res.resize(n);
	for (size_t i=0; i<(int) res.size(); ++i)
		res[i] = ll (fa[i].imag / 2 + 0.5);
}

vector <int> x, y, z;

vector <ll> _z;

big res;

big operator * (const big &a, const big &b)
{
    x = a.num;
    y = b.num;
    int n = x.size(), m = y.size();
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    {
        multiply(x, y, _z);
        /*
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                z[i + j] += x[i] * (ll) y[j];
            }
        }
        //fft
        */
    }
    for (int i = 0; i < n + m; i++)
    {
        _z[i + 1] += _z[i] / base;
        _z[i] %= base;
    }
    while (_z.size() > 0 && _z.back() == 0)
    {
        _z.pop_back();
    }
    reverse(_z.begin(), _z.end());
    big res;
    z.clear();
    for (ll x : _z) z.push_back(x);
    res.num = z;
    res.sign = a.sign * b.sign;
    return res;
}



big plus(const big &a, const big &b)
{
    auto &x = a.num;
    auto &y = b.num;
    int n = x.size(), m = y.size();
    int cur = max(n, m);
    z.assign(cur + 1, 0);
    for (int i = 0; i < n; i++)
    {
        z[i] += x[n - 1 - i];
    }
    for (int i = 0; i < m; i++)
    {
        z[i] += y[m - 1 - i];
    }
    for (int i = 0; i < cur; i++)
    {
        if (z[i] >= base)
        {
            z[i + 1]++;
            z[i] -= base;
        }
    }
    while (z.size() > 0 && z.back() == 0)
    {
        z.pop_back();
    }
    reverse(z.begin(), z.end());
    res.num = z;
    res.sign = 1;
    return res;
}

big minus(const big &a, const big &b)
{
    auto &x = a.num;
    auto &y = b.num;
    int n = x.size(), m = y.size();
    int cur = max(n, m);
    z.assign(cur + 1, 0);
    for (int i = 0; i < n; i++)
    {
        z[i] += x[n - 1 - i];
    }
    for (int i = 0; i < m; i++)
    {
        z[i] -= y[m - 1 - i];
    }
    for (int i = 0; i < cur; i++)
    {
        if (z[i] < 0)
        {
            z[i + 1]--;
            z[i] += base;
        }
    }
    while (z.size() > 0 && z.back() == 0)
    {
        z.pop_back();
    }
    reverse(z.begin(), z.end());
    res.num = z;
    res.sign = 1;
    return res;
}

big operator + (const big &a, const big &b)
{
    if (a.sign == 1 && b.sign == 1)
    {
        return plus(a, b);
    }
    if (a.sign == -1 && b.sign == -1)
    {
        res = plus(a, b);
        res.sign = -1;
        return res;
    }
    if (a.sign == 1 && b.sign == -1)
    {
        if (a > b)
        {
            res = minus(a, b);
            return res;
        }
        else
        {
            res = minus(b, a);
            res.sign = -1;
            return res;
        }
    }
    if (a.sign == -1 && b.sign == 1)
    {
        if (a > b)
        {
            res = minus(a, b);
            res.sign = -1;
            return res;
        }
        else
        {
            res = minus(b, a);
            return res;
        }
    }
    return a;
}

big neg(const big &a)
{
    res = a;
    res.sign *= -1;
    return res;
}

big operator / (const big &a, int b)
{
    z = a.num;
    int n = z.size();
    int um = 0;
    for (int i = 0; i < n; i++)
    {
        ll cur = z[i] + um * (ll) base;
        z[i] = (cur / b);
        um = (cur % b);
    }
    reverse(z.begin(), z.end());
    while (z.size() > 0 && z.back() == 0)
    {
        z.pop_back();
    }
    reverse(z.begin(), z.end());
    res.sign = a.sign;
    res.num = z;
    return res;
}

big operator * (const big &a, int b)
{
    z = a.num;
    int n = z.size();
    int um = 0;
    reverse(z.begin(), z.end());
    for (int i = 0; i < n; i++)
    {
        ll cur = um + z[i] * (ll) b;
        z[i] = (cur % base);
        um = (cur / base);
    }
    if (um)
    {
        z.push_back(um);
    }
    while (z.size() > 0 && z.back() == 0)
    {
        z.pop_back();
    }
    reverse(z.begin(), z.end());
    res.sign = a.sign;
    res.num = z;
    return res;
}


void print(const big &cur)
{
    if (cur.num.empty())
    {
        puts("0");
    }
    else
    {
        printf("%d", cur.num[0]);
        for (int i = 1; i < (int) cur.num.size(); i++)
        {
            printf("%05d", cur.num[i]);
        }
        puts("");
    }
}

big ur(const big &a, int cnt)
{
    z = a.num;
    int cur = cnt / digits;
    while (cur--)
    {
        z.push_back(0);
    }
    res.num = z;
    res.sign = a.sign;
    cnt %= digits;
    int x = 1;
    for (int it = 0; it < cnt; it++)
    {
        x *= 10;
    }
    return res * x;
}

big wr(const big &a, int cnt)
{
    z = a.num;
    int cur = cnt / digits;
    while (!z.empty() && cur)
    {
        z.pop_back();
        cur--;
    }
    res.num = z;
    res.sign = a.sign;
    cnt %= digits;
    int x = 1;
    for (int it = 0; it < cnt; it++)
    {
        x *= 10;
    }
    return res / x;
}

int num(string s)
{
    return atoi(s.c_str());
}

big get(string s)
{
    z.clear();
    for (int i = (int) s.size(); i > 0; i -= digits)
    {
        if (i < digits)
        {
            z.push_back(num(s.substr(0, i)));
        }
        else
        {
            z.push_back(num(s.substr(i - digits, digits)));
        }
    }
    reverse(z.begin(), z.end());
    res.num = z;
    res.sign = 1;
    return res;
}


int len;
int st;

big mul(const big &a, const big &b, int shift)
{
    return wr(a * b, shift);
}

string s;

big one = get("1");
big minus_one = neg(one);
big two = get("2");
big three = get("3");

big sqrt(big n, int shift)
{
    big x = ur(one, 1);
    if (shift > 4)
    {
        x = ur(one, shift - len / 2);
        if (s.size() >= 250000)
        {
            int gt = (int) s.size() % 2 == 0 ? 18 : 17;
            ll k = 0;
            for (int i = 0; i < gt; i++)
            {
                k = k * 10 + s[i] - '0'; 
            }
            long double p = sqrt(k);
            stringstream ss;
            string t = "";
            int kek = s.size() - gt;
            int cnt = shift - kek / 2;
            ss << fixed << setprecision(cnt) << 1 / p;
            char c;
            ss >> c;
            ss >> c;
            for (int i = 0; i < cnt; i++)
            {
                ss >> c;
                t += c;
            }
            x = get(t);
        }
    }
    big t = ur(three, shift);
    for (int it = 0; it < 21; it++)
    {
        big cur = n * mul(x, x, shift);
        cur = t + neg(cur);
        cur = mul(cur, x, shift);
        cur = cur / 2;
        x = cur;
    }
    return wr(x * n, shift);
}

big cur;

big f(big n)
{
    big x = sqrt(n, len + len / 2 + 1);
    cur = x * x;
    if (cur + x * 2 + one < n || !(cur + x * 2 + one > n))
    {
        x = x + one;
        cur = cur + x * 2 + one;
    }
    if (cur > n)
    {
        x = x + minus_one;
        cur = cur + neg(x * 2) + minus_one;
    }
    return x;
}

const int M = 125000 + 7;
const int A = 6;

int results[M][A][A];
bool vis[A];
int g[A][A];

void dfs(int v)
{
    vis[v] = true;
    for (int i = 0; i < A; i++)
    {
        if (g[v][i] && !vis[i])
        {
            dfs(i);
        }
    }
}

int ans()
{
    for (int i = 0; i < A; i++)
    {
        vis[i] = 0;
    }
    int res = A;
    for (int i = 0; i < A; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            res--;
        }
    }
    return res;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int it = 0;
    for (int len = 2; ; len *= 2)
    {
        long double ang = 2 * PI / len;
        bse wlen = bse(cos(ang), sin(ang));
        bse u(1, 0);
        for (int i = 0; i < len / 2; i++)
        {
            w[it++] = u;
            u = u * wlen;
            if (it >= 5e6)
            {
                break;
            }
        }
        if (it >= 5e6)
        {
            break;
        }
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int n = (int) s.size(), m = (int) t.size();
    for (char c = 'a'; c <= 'f'; c++)
    {
        for (char d = 'a'; d <= 'f'; d++)
        {
            if (c == d)
            {
                continue;
            }
            vector <int> x(n);
            for (int i = 0; i < n; i++)
            {
                if (s[i] == c) x[i] = 1;
            }
            vector <int> y(m);
            for (int i = 0; i < m; i++)
            {
                if (t[i] == d) y[m - 1 - i] = 1;
            }
            vector <ll> ans;
            multiply(x, y, ans);
            for (int i = m - 1; i < (int) ans.size(); i++)
            {
                if (ans[i])
                {
                    results[i - (m - 1)][c - 'a'][d - 'a']++;
                }
            }
        }
    }
    for (int i = 0; i + m - 1 < n; i++)
    {
        for (int x = 0; x < A; x++) for (int y = 0; y < A; y++) g[x][y] = results[i][x][y] + results[i][y][x];
        cout << ans() << ' ';
    }
    cout << '\n';
}