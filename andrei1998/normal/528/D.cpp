#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <complex>
#include <string>

#define c_double complex <double>
using namespace std;

const double PI = acos(-1);

int rev(int n, int k) {
    int res = 0;
    for (int i = 0; i < k; ++ i)
        if (n & (1 << i))
            res |= (1 << (k - i - 1));
    return res;
}

void fft(int k, vector <c_double> &v, bool inv = false) {
    int n = v.size();
    /*for (int i = 0; i < n; ++ i)
        if (i < rev(i, k))
            swap(v[i], v[rev(i, k)]);*/

    for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (v[i], v[j]);
	}

    c_double a, b;
    for (int len = 2; len <= n; len *= 2) {
        c_double w(cos(2 * PI / len), (1 - 2 * inv) * sin(2 * PI / len));

        for (int i = 0; i < n; i += len) {
            c_double wk(1);

            for (int j = 0; j < len / 2; ++ j) {
                a = v[i + j], b = v[i + j + len / 2] * wk;
                v[i + j] = a + b;
                v[i + j + len / 2] = a - b;

                wk *= w;
            }
        }
    }

    if (inv)
        for (int i = 0; i < n; ++ i)
            v[i] /= n;
}

vector <int> product(vector <int> a, vector <int> b) {
    int n = 1, k = 0;
    while (n < 2 * a.size() || n < 2 * b.size())
        n *= 2, ++ k;

    vector <c_double> ca(n), cb(n);

    for (int i = 0; i < a.size(); ++ i)
        ca[i] = a[i];
    for (int i = 0; i < b.size(); ++ i)
        cb[i] = b[i];

    fft(k, ca);
    fft(k, cb);

    vector <c_double> cans(n);
    for (int i = 0; i < n; ++ i)
        cans[i] = ca[i] * cb[i];

    fft(k, cans, true);

    vector <int> ans(n);
    for (int i = 0; i < n; ++ i)
        ans[i] = cans[i].real() + 0.5;

    while (ans.size() > a.size() + b.size() && !ans.back())
        ans.pop_back();
    return ans;
}

const int NMAX = 200005;

string input;

int n, m, k;
bool str[4][NMAX];
bool pattern[4][NMAX];

int mars_str[4][NMAX];

vector <int> convolutions[4];

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n >> m >> k;

    cin >> input;
    for (int i = 0; i < n; ++ i)
        if (input[i] == 'A')
            str[0][i] = 1;
        else if (input[i] == 'T')
            str[1][i] = 1;
        else if (input[i] == 'C')
            str[2][i] = 1;
        else //G
            str[3][i] = 1;

    cin >> input;
    for (int i = 0; i < n; ++ i)
        if (input[i] == 'A')
            pattern[0][i] = 1;
        else if (input[i] == 'T')
            pattern[1][i] = 1;
        else if (input[i] == 'C')
            pattern[2][i] = 1;
        else //G
            pattern[3][i] = 1;

    //Apply Mars' trick to str
    for (int type = 0; type < 4; ++ type) {
        for (int i = 0; i < n; ++ i)
            if (str[type][i]) {
                ++ mars_str[type][max(0, i - k)];
                -- mars_str[type][min(n, i + k + 1)];
            }

        for (int i = 0; i < n; ++ i) {
            if (i)
                mars_str[type][i] += mars_str[type][i - 1];
            str[type][i] = (bool)mars_str[type][i];
        }
    }

    //Invert the patters
    for (int type = 0; type < 4; ++ type)
        reverse(pattern[type], pattern[type] + m);

    //Compute convolutions
    for (int type = 0; type < 4; ++ type)
        convolutions[type] = product(vector <int>(str[type], str[type] + n), vector <int>(pattern[type], pattern[type] + m));

    int ans = 0;
    for (int i = m - 1; i < n + m; ++ i) {
        int sum = 0;
        for (int type = 0; type < 4; ++ type)
            sum += convolutions[type][i];
        ans += (sum == m);
    }

    cout << ans << '\n';
    return 0;
}