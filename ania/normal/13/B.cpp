#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;

#define fore(i,n) for(int i = 0; i < (n); i++)
#define fort(i,n) for(typeof((n).begin()) i = (n).begin(); i != (n).end(); i++)

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;

#define err(...) fprintf(stderr, __VA_ARGS__);

int xa[11], xb[11], ya[11], yb[11];

inline long long sqr(int a) { return 1LL * a * a; }

bool ons(int ax, int ay, int bx, int by, int cx, int cy)
{
	//printf("ons %d %d %d %d %d %d\n", ax,ay,bx,by,cx,cy);
	if(ax < min(bx,cx)) return 0;
	if(ax > max(bx,cx)) return 0;
	if(ay < min(by,cy)) return 0;
	if(ay > max(by,cy)) return 0;
	if(bx == cx || by == cy) return 1;
	int l11 = bx-ax, l12 = by-ay, l21 = cx-bx, l22 = cy-by;
	//printf("%d %d %d %d\n", l11, l12, l21, l22);
	return 1LL * l11 * l22 == 1LL * l12 * l21;
}

bool wr(int ax, int ay, int bx, int by, int cx, int cy)
{
	if(bx == cx) return wr(ay,ax,by,bx,cy,cx);
	int len = abs(bx-cx);
	int q = abs(bx-ax);
	if(q > len-q) q = len-q;
	if(q * 5 < len) return 0;
	return 1;
}

bool ok(int th)
{
	//printf("third %d\n", th);
	int fi,se;
	fi = 0;
	se = 1;
	if(th < 2) se = 2;
	if(th < 1) fi = 1;
	if(xa[fi] != xa[se] || ya[fi] != ya[se])
	{
		swap(xa[fi],xb[fi]);
		swap(ya[fi],yb[fi]);
	}
	if(xa[fi] != xa[se] || ya[fi] != ya[se])
	{
		swap(xa[se],xb[se]);
		swap(ya[se],yb[se]);
	}
	if(xa[fi] != xa[se] || ya[fi] != ya[se])
	{
		swap(xa[fi],xb[fi]);
		swap(ya[fi],yb[fi]);
	}
	if(xa[fi] != xa[se] || ya[fi] != ya[se])
	{
		return 0;
	}
	//printf("punkt ok\n");
	long long a = sqr(xa[fi]-xb[fi]) + sqr(ya[fi]-yb[fi]), b = sqr(xa[se]-xb[se]) + sqr(ya[se]-yb[se]), c = sqr(xb[fi]-xb[se]) + sqr(yb[fi]-yb[se]);
	if(a+b < c) return 0;
	//printf("kat ok\n");
	//printf("fi %d %d %d %d\nse %d %d %d %d\nth %d %d %d %d\n", xa[fi],ya[fi],xb[fi],yb[fi],xa[se],ya[se],xb[se],yb[se],xa[th],ya[th],xb[th],yb[th]);
	if(!ons(xa[th],ya[th], xa[fi],ya[fi],xb[fi],yb[fi]))
	{
		swap(xa[th],xb[th]);
		swap(ya[th],yb[th]);
	}
	//printf("fi %d %d %d %d\nse %d %d %d %d\nth %d %d %d %d\n", xa[fi],ya[fi],xb[fi],yb[fi],xa[se],ya[se],xb[se],yb[se],xa[th],ya[th],xb[th],yb[th]);
	if(!ons(xa[th],ya[th], xa[fi],ya[fi],xb[fi],yb[fi])) return 0;
	if(!ons(xb[th],yb[th], xa[se],ya[se],xb[se],yb[se])) return 0;
	//printf("onsegment ok\n");
	//printf("fi %d %d %d %d\nse %d %d %d %d\nth %d %d %d %d\n", xa[fi],ya[fi],xb[fi],yb[fi],xa[se],ya[se],xb[se],yb[se],xa[th],ya[th],xb[th],yb[th]);
	if(!wr(xa[th],ya[th], xa[se],ya[fi],xb[fi],yb[fi])) return 0;
	if(!wr(xb[th],yb[th], xa[se],ya[se],xb[se],yb[se])) return 0;
	//printf("ok\n");
	return 1;
}

void test()
{
	fore(i,3) scanf("%d%d%d%d", &xa[i], &ya[i], &xb[i], &yb[i]);
	fore(i,3) if(ok(i))
	{
		printf("YES\n");
		return;
	}
	printf("NO\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) test();
}