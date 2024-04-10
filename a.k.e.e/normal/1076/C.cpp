#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAXN=200005;

int T;

int main()
{
	int d;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&d);
		int del;
		del=d*d-4*d;
		if(del<0)printf("N\n");
		else
			printf("Y %.10lf %.10lf\n",(sqrt(del)+d)/2.0,(-sqrt(del)+d)/2.0);
	}
	return 0;
}