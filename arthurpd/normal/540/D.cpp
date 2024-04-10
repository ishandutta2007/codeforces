//http://codeforces.com/problemset/problem/540/D
#include <stdio.h>

struct ans{
	double pa, pb, pc;
	ans() : pa(0.0), pb(0.0), pc(0.0) {}
	ans(double x, double y, double z) : pa(x), pb(y), pc(z) {}
	ans operator *(double x)
	{
		return ans(pa * x, pb * x, pc * x);
	}
	ans operator +(ans x)
	{
		return ans(pa + x.pa, pb + x.pb, pc + x.pc);
	}
};

ans tab[112][112][112];

ans pd(int a, int b, int c)
{
	if(a < 0 || b < 0 || c < 0)
		return ans(0,0,0);
	if(b == 0 && c == 0)
		return ans(1,0,0);
	if(a == 0 && c == 0)
		return ans(0,1,0);
	if(a == 0 && b == 0)
		return ans(0,0,1); 
	if(tab[a][b][c].pa + tab[a][b][c].pb + tab[a][b][c].pc > 0.5)
		return tab[a][b][c];

	double prob_ab = (a*b) / (0.5*(a+b+c)*(a+b+c-1));
	double prob_ac = (a*c) / (0.5*(a+b+c)*(a+b+c-1));
	double prob_bc = (b*c) / (0.5*(a+b+c)*(a+b+c-1));
	double prob_not = 1 - prob_ab - prob_ac - prob_bc;

	return tab[a][b][c] = (pd(a, b-1, c)*prob_ab + pd(a-1, b, c)*prob_ac + pd(a, b, c-1)*prob_bc)*(1.0/(1 - prob_not));
}

int main(void)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	ans x = pd(a, b, c);
	printf("%.10lf %.10lf %.10lf\n", x.pa, x.pb, x.pc);
}

// x + x*p + x*p2
//s = x *(p^n - 1) / (p - 1)
//s_inf = a0 / (1 - p)