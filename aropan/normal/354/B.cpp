#include <queue>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define FOREACH(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

const int INF = (int)1e+9 + 7;
const int MAXN = 55;

typedef pair <int, int> mpair;

string s[MAXN];
int n;
map <mpair, int> M;

int get(int l, int m)
{
    mpair p = make_pair(l, m);
    if (M.find(p) != M.end())
        return M[p];
    int &r = M[p];
    
    if (l == 2 * n - 2)
    {
        r = 0;
    }
    else
    {
        if (l & 1)
            r = -INF;
        else
            r = INF;

        l += 1;
        int msk[26], ind = 0;
        memset(msk, 0, sizeof(msk));
        for (int i = 0; i <= l; i++)
        {
            int x = l - i;
            int y = i;
            if (x >= n || y >= n)
                continue;
            msk[s[x][y] - 'a'] |= 1 << ind;
            ind += 1;
        }
        l -= 1;
        
        for (int i = 0; i < 26; i++)
            if (msk[i])
            {
                int x;
                if (l + 1 < n)
                    x = (m | (m << 1)) & msk[i];
                else
                    x = (m | (m >> 1)) & msk[i];

                if (x == 0)
                    continue;
                    
                int d = i == 0? 1 : (i == 1? -1 : 0);
                //cout << "\t" << l << " " << m << " -> " << l + 1 << " " << x << endl;

                if (l & 1)
                    r = max(r, get(l + 1, x) + d);
                else
                    r = min(r, get(l + 1, x) + d);
            }
    }

    if (l == 0)
    {
        if (s[0][0] == 'a') r += 1; else
        if (s[0][0] == 'b') r -= 1;
    }
    //cout << "\t" << l << " " << m << " " << r << endl;
    return r;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    while (cin >> n)
    {
        M.clear();
        for (int i = 0; i < n; i++)
            cin >> s[i];

        int r = get(0, 1);

        if (r > 0) cout << "FIRST" << endl; else
        if (r < 0) cout << "SECOND" << endl; else
            cout << "DRAW" << endl;
        break;
    }
	return 0;
}