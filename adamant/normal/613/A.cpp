#include <bits/stdc++.h>

using namespace std;

// Geometric template
// Works in right orthonormal basis

#define int long double

 const double pi = 4 * atan(1);
 const double inf = 1e9;
 const double eps = 1e-9;

int n = 2;

void redim(int z) {n = z;}

 struct vec
 {
    int x, y, z;
    vec():x(0), y(0), z(0){}
    vec(int x):x(x), y(x), z(x){}
    vec(int x, int y):x(x), y(y), z(0){}
    vec(int x, int y, int z):x(x), y(y), z(z){}
 };

 istream & operator >>(istream &in, vec &v)
 {
    in >> v.x >> v.y;
    if(n == 3)
        in >> v.z;
    return in;
 }
 ostream & operator <<(ostream &out, vec v)
 {
    out << v.x << ' ' << v.y;
    if(n == 3) out << ' ' << v.z;
    return out;
 }

 bool operator ==(vec a, vec b) {return a.x == b.x && a.y == b.y && a.z == b.z;}
 bool operator !=(vec a, vec b) {return a.x != b.x || a.y != b.y || a.z != b.z;}
 vec operator +(vec a, vec b) {return vec(a.x + b.x, a.y + b.y, a.z + b.z);}
 vec operator -(vec a, vec b) {return vec(a.x - b.x, a.y - b.y, a.z - b.z);}
int operator *(vec a, vec b) {return a.x * b.x + a.y * b.y + a.z * b.z;}
 vec operator *(vec a, int b) {return vec(a.x * b, a.y * b, a.z * b);}
 vec operator *(int a, vec b) {return vec(b.x * a, b.y * a, b.z * a);}
 vec operator /(vec a, int b) {return vec(a.x / b, a.y / b, a.z / b);}
int operator %(vec a, vec b) {return a.x * b.y - a.y * b.x;} // 2 dimensional only
vec operator -(vec a) {return (-1) * a;}
int mod(vec a) {return sqrt(a * a);}


 vec vec_mul(vec a, vec b)
 {
    return vec(a.y * b.z - a.z * b.y,
               a.z * b.x - a.x * b.z,
               a.x * b.y - a.y * b.x);
 }

double angle(vec a, vec b)
 {
    return acos(a * b / mod(a) / mod(b));
 }

int tri_mul(vec a, vec b, vec c)
 {
    return a * vec_mul(b, c);
 }

 vec canonic(vec a, vec b) // x1 y1 x2 y2 -> (A, B, C)
{
    return vec(-(b - a).y, (b - a).x, a % b);
 }

 vec any_point(vec z) // on the line (A, B, C)
{
    return vec(-z.x * z.z, -z.y * z.z) / (z.x * z.x + z.y * z.y);
 }

 vec line_intersect(vec z1, vec z2) // (A1, B1, C1), (A2, B2, C2)
{
    vec A(z1.x, z2.x), B(z1.y, z2.y), C(z1.z, z2.z);
    if(A % B == 0) // fuck the singular cases
        if(vec_mul(z1, z2) == vec(0))
            return vec(+inf);
        else
            return vec(-inf);
    return vec(B % C, C % A) / (A % B); // cramer's rule, lol
}

 vec line_intersect(vec a, vec b, vec c, vec d) // two points for segment
{
    return line_intersect(canonic(a, b), canonic(c, d));
 }

 bool on_line(vec a, vec b, vec c) {return vec_mul(c - a, b - a) == vec(0);}
 bool on_segment(vec a, vec b, vec c) {return on_line(a, b, c) && (c - a) * (c - b) <= 0;}

 vec segment_intersect(vec a, vec b, vec c, vec d)
 {
    vec p = line_intersect(a, b, c, d);
    if(p == vec(+inf)) // double-fuck the singular cases
    {
        if(on_segment(a, b, c)) return c;
        if(on_segment(a, b, d)) return d;
        if(on_segment(c, d, a)) return a;
        if(on_segment(c, d, b)) return b;
        return vec(-inf);
    }
    if(!on_segment(a, b, p))
        return vec(-inf);
    if(!on_segment(c, d, p))
        return vec(-inf);
    return p;
 }

int dist(vec c, vec a, vec b)
 {
    if((c - a) * (b - a) < 0)
        return mod(c - a);
    else if((c - b) * (a - b) < 0)
        return mod(c - b);
    else
        return mod(vec_mul(b - c, a - c)) / mod(b - a);
 }
signed main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vec p;
	cin >> p;
	int rmax = 0, rmin = 1e18;
	vec x1, x2, x0;
	cin >> x1;
	x0 = x1;
	rmax = mod(p - x1);
	for(int i = 0; i < n - 1; i++)
	{
		cin >> x2;
		rmax = max(rmax, mod(p - x2));
		rmin = min(rmin, dist(p, x1, x2));
		swap(x1, x2);
	}
	rmin = min(rmin, dist(p, x1, x0));
	double PI = 4 * atan(1);
	cout << fixed << setprecision(7) << PI * rmax * rmax - PI * rmin * rmin << "\n";
	
}