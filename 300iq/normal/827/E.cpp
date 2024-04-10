#include <bits/stdc++.h>
#define PI 3.141592653589793238462643383279

using namespace std;

const int N = 5e5 + 1;

bitset <N> A;
bitset <N> b;

char c[N];

string get_str()
{
    scanf(" %s", c);
    return string(c);
}

typedef complex<double> base;
 
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

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        set <int> ans;
        for (int i = 1; i <= n; i++)
        {
            ans.insert(i);
        }
        int was = n;
        int kek = 1;
        while (kek < n)
        {
            kek *= 2;
        }
        kek *= 2;
        string s = get_str();
        while (s.size() < kek)
        {
            s += '?';
        }
        n = kek;
        vector <base> a, b;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'V')
            {
                a.push_back(base(1));
            }
            else
            {
                a.push_back(base(0));
            }
            if (s[i] == 'K')
            {
                b.push_back(base(1));
            }
            else
            {
                b.push_back(base(0));
            }
            if (i == was - 1)
            {
                reverse(b.begin(), b.end());
            }
        }
        fft(a, 0);
        fft(b, 0);
        for (int i = 0; i < n; i++)
        {
            a[i] *= b[i];
        }
        fft(a, 1);
        for (int i = was; i < n; i++)
        {
            if ((int) (a[i].real() + 0.5))
            {
                ans.erase(i - was + 1);
            }
        }
        for (int i = 0; i < was; i++)
        {
            if ((int) (a[i].real() + 0.5))
            {
                int ind = i - was + 1;
                ans.erase(abs(ind));
            }
        }
        for (int i = 1; i <= was; i++)
        {
            if (!ans.count(i))
            {
                for (int j = 1; j * j <= i; j++)
                {
                    if (i % j == 0)
                    {
                        ans.erase(j);
                        ans.erase(i / j);
                    }
                }
            }
        }
        printf("%d\n", (int) ans.size());
        for (int c : ans)
        {
            printf("%d ", c);
        }
        puts("");
    }
}