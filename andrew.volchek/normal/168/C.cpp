#include <iostream>
#include <math.h>

using namespace std;

struct tr
{
	unsigned long long t;
	unsigned long long v;
	double tk;
};

int main()
{
	long n,a,d;
	cin >> n >> a >> d;
	cin.ignore();
	tr *T = new tr[n];
	for(long i=0;i<n;i++)
	{
		cin >> T[i].t >> T[i].v;
		cin.ignore();
	}

	for(long i=0;i<n;i++)
	{
		double t1 = (double)T[i].v / a;
		double s1 = (T[i].v*T[i].v)/(a*2.0f);

		if(d - s1 > 1e-6)
		{
			double t2 = (d-s1)/T[i].v;
			T[i].tk = t1 + t2 + T[i].t;
		}
		else
		{
			double t2 = sqrt((double)(d*2.0f/a));
			T[i].tk = t2 + T[i].t;
		}
		if(i)
		{
			double tk = T[i].tk;
			if(T[i].t < T[i-1].tk && tk < T[i-1].tk)
				tk = T[i-1].tk;
			T[i].tk = tk;
		}
	}

	
	cout.setf(ios_base::fixed);
	cout.precision(10);

	for(long i=0;i<n;i++)
	{
		cout << T[i].tk << '\n';
	}
	
	return 0;
}