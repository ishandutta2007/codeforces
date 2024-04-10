#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

const int maxn = 200005;
char a[maxn], b[maxn];

ull x[64][maxn], y[64][maxn];

union S
{
	ull x;
	std::uint16_t  a[4];
};

int cnt[1 << 16];
ull msk = (1 << 16) - 1;
inline int f(S x)
{
    return cnt[x.a[0]] + cnt[x.a[1]] + cnt[x.a[2]] + cnt[x.a[3]];// + cnt[(x >> 32) & msk] + cnt[(x >> 48) & msk];
}



void gen()
{
	freopen("a.in", "w", stdout);
	for (int i = 0; i < 200000; i++)
		cout << "1";
	cout << endl;
	for (int i = 0; i < 200000; i++)
		cout << "1";
	cout << endl;
	cout << 400000 << endl;;
	for (int i = 0; i < 400000; i++)
		cout << 0 << " " << 0 << " " << 200000 << endl;
		exit(0);
}

int main()
{
	//gen();
    //freopen("a.in", "r", stdin);
    gets(a);
    gets(b);
    
    for (int i = 1; i < (1 << 16); i++)
		for (int j = 0; j < 16; j++)
			if (i & (1 << j))
				cnt[i]++;
	
    
    
    int len = strlen(a);
	for (int h = 0; h < 64; h++)
		for (int i = h; i < len; i++)
		{
			int j = (i - h) >> 6;
			if (a[i] == '1')
				x[h][j] |= 1ULL << (63 - (i - h) + (j << 6));
		}
    len = strlen(b);
    for (int h = 0; h < 64; h++)
		for (int i = h; i < len; i++)
		{
			int j = (i - h) >> 6;
			if (b[i] == '1')
				y[h][j] |= 1ULL << (63 - (i - h) + (j << 6));
		}
    
    int q;
    scanf("%d", &q);
    //q = 400000;
    vector < int > aa;
    for (int i = 0; i < q; i++)
    {
        int p1, p2, l;
        scanf("%d %d %d", &p1, &p2, &l);
       //p1 = rand() % 10000;
       //p2 = rand() % 10000;
     // l = 0;
		int h1 = p1 & 63;
		int h2 = p2 & 63;
		int f1 = p1 >> 6;
		int f2 = p2 >> 6;
		int ans = 0;
		while (l)
		{
			if (l >= 64)
			{
				//ans += f(x[h1][f1] ^ y[h2][f2]);
				
				S d;
				d.x = x[h1][f1] ^ y[h2][f2];
				ans += f(d);
				f1++;
				f2++;
				l -= 64;
			}
			else
			{
				ull u = x[h1][f1];
				ull v = y[h2][f2];
				u >>= 64 - l;
				v >>= 64 - l;
				//ans += f(u ^ v);
				S d;
				d.x = u ^ v;
				ans += f(d);
				break;
			}
		}
        
        printf("%d\n", ans);
       //aa.pb(ans);
    }
    
   // for (int i = 0; i < aa.size(); i++)
	//	printf("%d\n", aa[i]);
    //cerr << (ld)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}