#include<bits/stdc++.h>
using namespace std;
int x,y,z,t1,t2;
double s[100],p1,p2;
const double eps=1e-8;
inline int work(double x)
{
	if (x>s[1]-eps&&x<s[2]+eps)
		return 1;
	if (x>s[2]-eps&&x<s[3]+eps)
		return 2;
	return 3;
}
int main()
{
	scanf("%d%d%d%d%d",&x,&y,&z,&t1,&t2);
	s[3]=z*6;
	s[2]=(y+(double)z/60)*6;
	s[1]=(x+(double)y/60+(double)z/3600)*30;
	p1=t1*30;
	p2=t2*30;
	sort(s+1,s+4);
	if (work(p1)==work(p2))
		puts("YES");
	else
		puts("NO");
}