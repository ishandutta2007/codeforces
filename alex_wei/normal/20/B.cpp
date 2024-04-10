#include<bits/stdc++.h>
using namespace std;
double a,b,c,p;
int main()
{
	cin>>a>>b>>c;
	if(a==0){
		if(b==0){
			if(c==0)printf("-1");
			else printf("0");
		}
		else printf("1\n%.5lf",-c/b);
	}
	else{
		p=b*b-4*a*c;
		if(p<0)printf("0"),exit(0);
		double roota=(-b+sqrt(p))/2/a,rootb=(-b-sqrt(p))/2/a;
		if(roota==rootb)printf("1\n%.5lf",roota);
		else printf("2\n%.5lf\n%.5lf",min(roota,rootb),max(roota,rootb));
	}
	return 0;
}