#include<cstdio>
#include<algorithm>
using namespace std;
int arr[200000];
double mindp[200001];
double maxdp[200001];
int N;
bool can(double a)
{
	double minans=0;
	double maxans=0;
	mindp[0]=0;
	maxdp[0]=0;
	for(int i=1;i<=N;i++)
	{
		double v = arr[i] - a;
		mindp[i]=min(0.,mindp[i-1]+v);
		minans=min(mindp[i],minans);
		maxdp[i]=max(0.,maxdp[i-1]+v);
		maxans=max(maxdp[i],maxans);
	}
	return (minans+maxans)>0;
	// minimum < maximum value than true?
	
}
double solve(double a)
{
	double maxans=0;
	maxdp[0]=0;
	for(int i=1;i<=N;i++)
	{
		double v = arr[i]-a;
		maxdp[i]=max(0.,maxdp[i-1]+v);
		maxans=max(maxdp[i],maxans);
	}
	return maxans;
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",arr+i);
	double lo = -20000;
	double hi =  20000;
	for(int _=0;_<200;_++)
	{
		double mi=(lo+hi)/2;
		if(can(mi)) lo=mi;
		else hi=mi;
	}
	printf("%.12lf",solve(lo));
}