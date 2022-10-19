#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>

using namespace std;

typedef int64_t LL;
typedef pair<LL, LL> PL;
typedef pair<PL, PL> PPL;
#define fi first
#define se second

LL nextInt()
{
    LL ans = 0; char ch = getchar();
    while (ch == ' ' || ch == '\n') ch = getchar();
    while (47 < ch && ch < 58) ans = ans * 10 + ch - 48, ch = getchar();
    return ans;
}

const int MAX = 1001000;
int n;
LL k;
vector<PL> G[MAX];
vector<PPL> ranges[2];
vector<LL> A;

void dfs(int u, LL w)
{
    A.push_back(w);
    for (PL p : G[u]) dfs(p.fi, w ^ p.se);
}

LL sqr(LL x) { return x * x; }

int32_t main()
{
//	freopen("test.txt", "r", stdin);
	n = nextInt(), k = nextInt() - 1;
//	k = 13; --k;
    A.reserve(n);
    for (int u = 2; u <= n; ++u) {
		LL p = nextInt(), w = nextInt();
        G[p].push_back(PL(u, w));
    }
	dfs(1, 0);

    sort(A.begin(), A.end());
//    for (LL x : A) cerr << x << endl; return 0;

    LL ans = 0;
    ranges[0].reserve(n); ranges[1].reserve(n);
    ranges[0].push_back(PPL(PL(0, A.size()), PL(0, A.size())));
    for (int bit = 61; bit >= 0; --bit) {
        ranges[1].clear();
        LL cnt = 0;
//        if (bit == 0) cerr << k << endl;

        for (PPL ppl : ranges[0]) {
            PL p1 = ppl.fi, p2 = ppl.se;
//			if (bit == 0) cerr << p1.fi << ' ' << p1.se << ", " << p2.fi << ' ' << p2.se << endl;

            if (p1 == p2) {
				LL tmp = 0;
				for (int i = p1.fi; i < p1.se; ++i) {
					if ((A[i] >> bit) & 1) break;
					else ++tmp;
				}
                cnt += sqr(tmp) + sqr(p1.se - p1.fi - tmp);
//                cnt += tmp * (tmp - 1);
//                cnt += (p1.se - p1.fi - tmp) * (p1.se - p1.fi - tmp - 1);
            } else {
				LL tmp1 = 0, tmp2 = 0;
				for (int i = p1.fi; i < p1.se; ++i) {
					if ((A[i] >> bit) & 1) break;
					else ++tmp1;
				}
				for (int i = p2.fi; i < p2.se; ++i) {
					if ((A[i] >> bit) & 1) break;
					else ++tmp2;
				}
//				if (bit == 0) cerr << tmp1 << ' ' << tmp2 << endl;
                cnt += 2 * tmp1 * tmp2;
                cnt += 2 * (p1.se - p1.fi - tmp1) * (p2.se - p2.fi - tmp2);
			}
//			if (bit == 1) cerr << cnt << endl;
        }

//        if (bit == 0) cerr << cnt << endl;

        if (cnt <= k) {
            ans |= (1ll << bit);
            k -= cnt;
			for (PPL ppl : ranges[0]) {
				PL p1 = ppl.fi, p2 = ppl.se;
                if (p1 == p2) {
					int i;
					for (i = p1.fi; i < p1.se; ++i) {
						if ((A[i] >> bit) & 1) break;
					}
                    if (p1.fi != i && i != p1.se)
						ranges[1].push_back(PPL(PL(p1.fi, i), PL(i, p1.se)));
                } else {
                    int i1, i2;
					for (i1 = p1.fi; i1 < p1.se; ++i1) {
						if ((A[i1] >> bit) & 1) break;
					}
					for (i2 = p2.fi; i2 < p2.se; ++i2) {
						if ((A[i2] >> bit) & 1) break;
					}
                    if (p1.fi != i1 && i2 != p2.se)
						ranges[1].push_back(PPL(PL(p1.fi, i1), PL(i2, p2.se)));
                    if (p2.fi != i2 && i1 != p1.se)
						ranges[1].push_back(PPL(PL(p2.fi, i2), PL(i1, p1.se)));
                }
			}
        } else {
			for (PPL ppl : ranges[0]) {
				PL p1 = ppl.fi, p2 = ppl.se;
                if (p1 == p2) {
					int i;
					for (i = p1.fi; i < p1.se; ++i) {
						if ((A[i] >> bit) & 1) break;
					}
                    if (p1.fi != i)
						ranges[1].push_back(PPL(PL(p1.fi, i), PL(p1.fi, i)));
                    if (p1.se != i)
						ranges[1].push_back(PPL(PL(i, p1.se), PL(i, p1.se)));
                } else {
                    int i1, i2;
					for (i1 = p1.fi; i1 < p1.se; ++i1) {
						if ((A[i1] >> bit) & 1) break;
					}
					for (i2 = p2.fi; i2 < p2.se; ++i2) {
						if ((A[i2] >> bit) & 1) break;
					}
                    if (p1.fi != i1 && p2.fi != i2)
						ranges[1].push_back(PPL(PL(p1.fi, i1), PL(p2.fi, i2)));
                    if (i1 != p1.se && i2 != p2.se)
						ranges[1].push_back(PPL(PL(i1, p1.se), PL(i2, p2.se)));
                }
			}
        }

        ranges[0].swap(ranges[1]);
    }

    cout << ans;
}