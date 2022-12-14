#include<bits/stdc++.h>
using namespace std;
typedef complex<double> cd;
typedef long long ll;

const int maxn = 2e6 + 5;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

bool mark[maxn];

int main(){
	int n, m;
	cin >> n >> m;
	m ++;
	vector<int> a(m);
	a[0] = 1;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		a[x] = 1;
		mark[x] = 1;
	}
	a = multiply(a, a);
	for (int i = 1; i < m; i++)
		if (mark[i] == 0 and 0 < a[i])
			return cout << "NO\n", 0;
	int cnt = 0;
	for (int i = 1; i < m; i++)
		if (mark[i] == true and a[i] == 2)
			cnt ++;
	cout << "YES\n";
	cout << cnt << '\n';
	for (int i = 1; i < m; i++)
		if (mark[i] == true and a[i] == 2)
			cout << i << " ";
	cout << '\n';
}