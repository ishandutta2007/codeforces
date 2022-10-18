#include <bits/stdc++.h>

using namespace std;

/*
,     - !!!
*/

typedef complex<double> base;

const double PI = 4 * atan(1);

void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();

	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}

	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);

	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);

	res.resize (n);
	for (size_t i=0; i<n; ++i)
		res[i] = int (fa[i].real() + 0.5);
}

int main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    string a, b;
    cin >> a >> b;
    string sigma = "ACTG";
    vector<int> sum(n);
    for(auto c: sigma)
    {
        vector<int> A(n, 1);
        vector<int> B(m);
        for(int i = 0; i < m; i++)
            if(b[i] == c)
                B[i] = 1;
        vector<int> occ{-k - 1, n + k};
        for(int i = 0; i < n; i++)
            if(a[i] == c)
            occ.push_back(i);
        sort(occ.begin(), occ.end());
        for(int i = 1; i < occ.size(); i++)
        {
            int l = occ[i - 1];
            int r = occ[i];
            for(int j = l + k + 1; j < r - k; j++)
                A[j] = 0;
        }
        vector<int> C;
        reverse(B.begin(), B.end());
        multiply(A, B, C);
        for(int i = 0; i < n; i++)
            sum[i] += C[i + m - 1];
        /* for(auto it: A)
            cout << it << ' ';
        cout << endl;
        for(auto it: B)
            cout << it << ' ';
        cout << endl;
        for(auto it: C)
            cout << it << ' ';
        cout << endl;*/

    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += sum[i] == m;
    cout << ans << "\n";
    return 0;
}