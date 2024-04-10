#include <iostream>
using namespace std;
const int N=5005,INF=99999999;
struct ban
{
	long double a,b;
};

int n;
long double m;
ban t[N];
int main()
{
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(9);
	cin>>n>>m;
	for(int i=0;i<n;++i)
		cin>>t[i].a>>t[i].b;
	long double a=t[0].a;
	long double b=t[0].b;
	for(int i=1;i<n;++i)
	{
		if(t[i].a*b<t[i].b*a)
		{
			a=t[i].a;
			b=t[i].b;
		}
	}
	long double ans=a/b*m;
	cout<<ans<<endl;
//	system("pause");
	return 0;
}