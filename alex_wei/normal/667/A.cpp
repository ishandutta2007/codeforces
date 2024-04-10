#include<bits/stdc++.h>
using namespace std;
const double Pi=acos(-1);
double d,h,v,e,area,cubic;
int main()
{
	cin>>d>>h>>v>>e;
	area=d*d*Pi/4;
	cubic=h*area;
	if(e*area>=v)puts("NO");
	else printf("YES\n%.10lf",cubic/(v-e*area));
	return 0;
}