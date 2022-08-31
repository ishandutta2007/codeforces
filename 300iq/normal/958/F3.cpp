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

vector <int> multiply (const vector<int> & a, const vector<int> & b)
{
	size_t n = 1;
	while (n < a.size() + b.size())  n <<= 1;
	fa.resize (n);
    for (int i = 0; i < n; i++)
    {
        if (i < (int) a.size() && i < (int) b.size())
        {
            fa[i] = bse(a[i], b[i]);
        }
        else if (i < (int) a.size())
        {
            fa[i] = bse(a[i], 0);
        }
        else if (i < (int) b.size())
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
    vector <int> res(n);
	for (size_t i=0; i<(int) res.size(); ++i)
    {
		res[i] = (ll (fa[i].imag / 2 + 0.5)) % 1009;
    }
    while (!res.empty() && res.back() == 0)
    {
        res.pop_back();
    }
    return res;
}

int cnt[200000];


vector <int> solve(int l, int r)
{
    if (r - l == 1)
    {
        vector <int> ans(cnt[l] + 1, 1);
        return ans;
    }
    else
    {
        int m = (l + r) / 2;
        return multiply(solve(l, m), solve(m, r));
    }
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
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        cnt[x]++;
    }
    auto ans = solve(0, m);
    cout << ans[k] << '\n';
}