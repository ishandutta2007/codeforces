#include <stdio.h>

int leap(int a, int b)
{
	int retv = 0;
	for(; a <= b; a++)
		if(a % 4 == 0 && (a % 100 != 0 || a % 400 == 0))
			retv++;
	return retv;
}

int days(int m, int d, int l)
{
	int retv = 0;
	if(m > 1) retv += 31;
	if(m > 2) retv += 28 + l;
	if(m > 3) retv += 31;
	if(m > 4) retv += 30;
	if(m > 5) retv += 31;
	if(m > 6) retv += 30;
	if(m > 7) retv += 31;
	if(m > 8) retv += 31;
	if(m > 9) retv += 30;
	if(m > 10) retv += 31;
	if(m > 11) retv += 30;
	retv += (d-1);
	return retv;
}

int
main(void)
{
	int ai,mi,di,af,mf,df, tmp1, tmp2, tmp3;
	char c;
	scanf("%d%c%d%c%d", &ai, &c, &mi, &c, &di);
	scanf("%d%c%d%c%d", &af, &c, &mf, &c, &df);
	if(ai != af)
	{
		if(ai > af)
		{
		tmp1 = af; tmp2 = mf; tmp3 = df;
		af = ai; mf = mi; df = di;
		ai = tmp1; mi = tmp2; di = tmp3;
		}
	}
	else
	{
		if(mi != mf)
		{
			if(mi > mf)
			{
				tmp1 = af; tmp2 = mf; tmp3 = df;
				af = ai; mf = mi; df = di;
				ai = tmp1; mi = tmp2; di = tmp3;
			}
		}
		else if(di > df)
		{
			tmp1 = af; tmp2 = mf; tmp3 = df;
			af = ai; mf = mi; df = di;
			ai = tmp1; mi = tmp2; di = tmp3;
		}
	}
	int ans = ((af-ai-1) * 365) + leap(ai+1,af-1);
	if(af == ai)
	{
		ans = days(mf, df, leap(af,af)) - days(mi, di, leap(ai,ai));
	}
	else
	{
		ans += (365+leap(ai,ai)) - days(mi, di, leap(ai,ai));
		ans += days(mf, df, leap(af,af));
	}
	printf("%d\n", ans);
	return 0;
}