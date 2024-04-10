#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 2000006;

int n;
char a[N];

vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

void solv()
{
    scanf(" %s", a);
    n = strlen(a);
    int p = 0, s = n - 1;
    while (p < s)
    {
        if (a[p] != a[s])
        {
            break;
        }
        ++p;
        --s;
    }
    int maxp = 0;
    string b = "";
    for (int i = p; i <= s; ++i)
    {
        b += a[i];
    }
    string c = b;
    c += '#';
    reverse(b.begin(), b.end());
    c += b;
    vector<int> z = z_function(c);
    for (int i = (int)c.size() - 1; i >= 0; --i)
    {
        if (c[i] == '#')
            break;
        if (i + z[i] == (int)c.size())
        {
            maxp = z[i];
        }
    }
    int maxs = 0;
    b = "";
    for (int i = s; i >= p; --i)
    {
        b += a[i];
    }
    c = b;
    c += '#';
    reverse(b.begin(), b.end());
    c += b;
    z = z_function(c);
    for (int i = (int)c.size() - 1; i >= 0; --i)
    {
        if (c[i] == '#')
            break;
        if (i + z[i] == (int)c.size())
        {
            maxs = z[i];
        }
    }
    string ans = "";
    if (maxp > maxs)
    {
        for (int i = 0; i < p + maxp; ++i)
            ans += a[i];
        for (int i = s + 1; i < n; ++i)
            ans += a[i];
    }
    else
    {
        for (int i = 0; i < p; ++i)
            ans += a[i];
        for (int i = s - maxs + 1; i < n; ++i)
            ans += a[i];
    }
    cout << ans << endl;
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}