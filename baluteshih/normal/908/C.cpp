#include <iostream>
#include <math.h>
using namespace std;

double ans[1000],data[1000],R;

int main()
{
	int n,i,j;
	cin >> n >> R;
	for(i=0;i<n;i++)
	{
		cin >> data[i],ans[i]=R;
		for(j=0;j<i;j++)
			if((data[j]-data[i])*(data[j]-data[i])<=4*R*R) ans[i]=max(ans[j]+sqrt(4*R*R-(data[j]-data[i])*(data[j]-data[i])),ans[i]);
	}
	for(printf("%.6lf",ans[0]),i=1;i<n;i++)
		printf(" %.6lf",ans[i]);
	cout << "\n";
}