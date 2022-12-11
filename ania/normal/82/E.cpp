#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

typedef pair<double,double> pd;
#define x first
#define y second
const double eps = 1e-8;

int n,h,f;
int l[555], r[555];

inline pd get(double k, int mult)
{
	return make_pair(1.0 * k / (h-f) * mult, 1.0 * k * f / (f-h));
}

inline double val(pd F, double arg)
{
	return F.x*arg+F.y;
}

double calc(double p, double q, pd L, pd G)
{
	//printf("caleczka od %lf do %lf z (%lf-%lf)y + (%lf-%lf)\n", p, q, L.x, G.x, L.y, G.y);
	double Y = (G.y-L.y) / (L.x-G.x);
	if(val(L,p)<val(G,p)) p = Y;
	if(val(L,q)<val(G,q)) q = Y;
	//printf("caleczka od %lf do %lf z (%lf-%lf)y + (%lf-%lf)\n", p, q, L.x, G.x, L.y, G.y);
	double c2 = (L.x-G.x)/2, c1 = (L.y-G.y);
	return c2*(q*q-p*p) + c1*(q-p);
}

double cut(int i, int j)
{
	if((l[i]+r[i] < 0) != (l[j]+r[j] < 0)) return 0;
	pd L1 = get(eps+abs(l[i]),1), L2 = get(eps+abs(r[i]),1), G1 = get(eps+abs(l[j]),-1), G2 = get(eps+abs(r[j]),-1);
	if(l[i]+r[i] < 0)
	{
		swap(L1,L2);
		swap(G1,G2);
	}
	//printf("%lf %lf, %lf %lf, %lf %lf, %lf %lf\n", L1.x, L1.y, L2.x, L2.y, G1.x, G1.y, G2.x, G2.y);
	double yL = (L1.y-G1.y) / (G1.x-L1.x), yR = (L2.y-G2.y) / (G2.x-L2.x);
	yL = max(yL, 0.0);
	yL = min(yL, 1.0*h);
	yR = max(yR, 0.0);
	yR = min(yR, 1.0*h);
	//printf("yL = %lf, yR = %lf\n", yL, yR);
	double res = calc(0, min(yL,yR), G2, L1) + calc(max(yL,yR), h, L2, G1);
	if(yL < yR) return res + calc(yL, yR, G2, G1);
	else return res + calc(yR, yL, L2, L1);
}

int main()
{
	double res = 0;
	scanf("%d%d%d", &n, &h, &f);
	for(int i = 0; i < n; i++)
		scanf("%d%d", &l[i], &r[i]);
	for(int i = 0; i < n; i++) if(l[i] < 0 && r[i] > 0)
	{
		l[n] = l[i];
		r[n] = 0;
		l[i] = 0;
		n++;
		break;
	}
	for(int i = 0; i < n; i++)
	{
		res += 4.0 * (r[i]-l[i]) * f * h / (f-h);
	}
	//printf("%lf\n", res);
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
	{
		res -= 2.0 * cut(i,j);
		//printf("res=%lf\n",res);
	}
	printf("%.6lf\n", res);
}