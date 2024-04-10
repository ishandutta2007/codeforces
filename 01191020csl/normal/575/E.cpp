#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
struct point {
	int x, y;
	point(){}
	point(int a,int b):x(a),y(b){}
}p[800001];
inline point operator-(const point &a, const point &b) {
	return point(a.x-b.x,a.y-b.y);
}
inline long long cross(const point &a, const point &b) {
	return 1ll*a.x*b.y-1ll*a.y*b.x;
}
bool cmp(const point &a, const point &b) {
	if (cross(a-p[1], b-p[1]) == 0) {
		if (a.y == b.y) return a.x < b.x;
		return a.y < b.y;
	}
	return cross(a-p[1], b-p[1]) > 0;
}
inline long double length(point A) {
	return sqrt(1ll*A.x*A.x+1ll*A.y*A.y);
}
inline long double getR(point A, point B, point C) {
	return length(B-C)*length(B-A)*length(C-A)/(4.0*fabs(cross(B-A, C-A)));
}
int cnt = 0;
const int SIZE = 100000;
point polygram[800010];
int tot;
point ans1, ans2, ans3;
int main() {
	int n = read();
	for (int i = 1; i <= n; i++) {
		int x, y, d;
		x = read(), y = read(), d = read();
		point p0;
		p0 = point(0,0);if (abs(p0.x-x)+abs(p0.y-y)<=d) p[++cnt]=p0;
		p0 = point(0,SIZE);if (abs(p0.x-x)+abs(p0.y-y)<=d) p[++cnt]=p0;
		p0 = point(SIZE,0);if (abs(p0.x-x)+abs(p0.y-y)<=d) p[++cnt]=p0;
		p0 = point(SIZE,SIZE);if (abs(p0.x-x)+abs(p0.y-y)<=d) p[++cnt]=p0;
		p0 = point(x,y+d);if (abs(p0.x-SIZE/2)<=SIZE/2&&abs(p0.y-SIZE/2)<=SIZE/2) p[++cnt]=p0;
		p0 = point(x,y-d);if (abs(p0.x-SIZE/2)<=SIZE/2&&abs(p0.y-SIZE/2)<=SIZE/2) p[++cnt]=p0;
		p0 = point(x+d,y);if (abs(p0.x-SIZE/2)<=SIZE/2&&abs(p0.y-SIZE/2)<=SIZE/2) p[++cnt]=p0;
		p0 = point(x-d,y);if (abs(p0.x-SIZE/2)<=SIZE/2&&abs(p0.y-SIZE/2)<=SIZE/2) p[++cnt]=p0;
		p0 = point(0,x+y+d);if (abs(p0.y-SIZE/2)<=SIZE/2&&abs(p0.x-x)+abs(p0.y-y)<=d) p[++cnt]=p0;
		p0 = point(0,x+y-d);if (abs(p0.y-SIZE/2)<=SIZE/2&&abs(p0.x-x)+abs(p0.y-y)<=d) p[++cnt]=p0;
		p0 = point(0,y-x+d);if (abs(p0.y-SIZE/2)<=SIZE/2&&abs(p0.x-x)+abs(p0.y-y)<=d) p[++cnt]=p0;
		p0 = point(0,y-x-d);if (abs(p0.y-SIZE/2)<=SIZE/2&&abs(p0.x-x)+abs(p0.y-y)<=d) p[++cnt]=p0;
		p0 = point(SIZE,x+y+d-SIZE);if (abs(p0.y-SIZE/2)<=SIZE/2&&abs(p0.x-x)+abs(p0.y-y)<=d) p[++cnt]=p0;
		p0 = point(SIZE,x+y-d-SIZE);if (abs(p0.y-SIZE/2)<=SIZE/2&&abs(p0.x-x)+abs(p0.y-y)<=d) p[++cnt]=p0;
		p0 = point(SIZE,y-x+d+SIZE);if (abs(p0.y-SIZE/2)<=SIZE/2&&abs(p0.x-x)+abs(p0.y-y)<=d) p[++cnt]=p0;
		p0 = point(SIZE,y-x-d+SIZE);if (abs(p0.y-SIZE/2)<=SIZE/2&&abs(p0.x-x)+abs(p0.y-y)<=d) p[++cnt]=p0;
		p0 = point(x+y+d,0);if (abs(p0.x-SIZE/2)<=SIZE/2&&abs(p0.x-x)+abs(p0.y-y)<=d) p[++cnt]=p0;
		p0 = point(x+y-d,0);if (abs(p0.x-SIZE/2)<=SIZE/2&&abs(p0.x-x)+abs(p0.y-y)<=d) p[++cnt]=p0;
		p0 = point(x-y+d,0);if (abs(p0.x-SIZE/2)<=SIZE/2&&abs(p0.x-x)+abs(p0.y-y)<=d) p[++cnt]=p0;
		p0 = point(x-y-d,0);if (abs(p0.x-SIZE/2)<=SIZE/2&&abs(p0.x-x)+abs(p0.y-y)<=d) p[++cnt]=p0;
		p0 = point(x+y+d-SIZE,SIZE);if (abs(p0.x-SIZE/2)<=SIZE/2&&abs(p0.x-x)+abs(p0.y-y)<=d) p[++cnt]=p0;
		p0 = point(x+y-d-SIZE,SIZE);if (abs(p0.x-SIZE/2)<=SIZE/2&&abs(p0.x-x)+abs(p0.y-y)<=d) p[++cnt]=p0;
		p0 = point(x-y+d+SIZE,SIZE);if (abs(p0.x-SIZE/2)<=SIZE/2&&abs(p0.x-x)+abs(p0.y-y)<=d) p[++cnt]=p0;
		p0 = point(x-y-d+SIZE,SIZE);if (abs(p0.x-SIZE/2)<=SIZE/2&&abs(p0.x-x)+abs(p0.y-y)<=d) p[++cnt]=p0;
	}
	for (int i = 1; i <= cnt; i++)
		if (p[i].y < p[1].y || (p[i].y == p[1].y && p[i].x < p[1].x)) swap(p[1], p[i]);
	sort(p + 2, p + cnt + 1, cmp);
	polygram[1] = p[1], tot = 1;
	for (int i = 2; i <= cnt; i++) 
		if (p[i].x != p[1].x || p[i].y != p[1].y) {
			while (tot >= 2 && cross(polygram[tot]-polygram[tot-1], p[i]-polygram[tot]) <= 0) --tot;
			polygram[++tot] = p[i];
		}
	polygram[++tot] = polygram[1], polygram[++tot] = polygram[2];
	long double R = 0;
	for (int i = 1; i <= tot - 2; i++) {
		long double r = getR(polygram[i], polygram[i+1], polygram[i+2]);
		if (r > R) R = r, ans1 = polygram[i], ans2 = polygram[i+1], ans3 = polygram[i+2];
	}
	cout << ans1.x << ' ' << ans1.y << endl;
	cout << ans2.x << ' ' << ans2.y << endl;
	cout << ans3.x << ' ' << ans3.y << endl;
}