#include <stdio.h>

inline int ABS(int a)
{
	if(a<0) return -a;
	else return a;
}

int main()
{
	int s, x1, x2, t1, t2, p, d;
	scanf("%d %d %d %d %d %d %d", &s, &x1, &x2, &t1, &t2, &p, &d);

	int dist;
	if(d==1) {
		if(p<=x1 && x1<=x2)
			dist=(x2-p);
		else if((x2-x1)>=0) {
			dist=(s-p)+s+x2;
		}
		else
			dist=(s-p)+(s-x2);
	}
	else {
		if(p>=x1 && x1>=x2)
			dist=(p-x2);
		else if(x2-x1<=0) 
			dist=p+s+(s-x2);
		else
			dist=p+x2;
	}

	if(dist*t1>ABS(x2-x1)*t2) 
		printf("%d\n",ABS(x2-x1)*t2);
	else
		printf("%d\n",dist*t1);

	return 0;
}