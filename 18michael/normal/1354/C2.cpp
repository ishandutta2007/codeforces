#include<bits/stdc++.h>
#define pai acos(-1)
using namespace std;
int n,Test_num;
inline double calc(int n)
{
	int t1=n/2,t2=t1+1;
	double Theta=1.0/n*pai,r=1/sin(Theta)*sin((pai-Theta)/2),Theta1=t1*Theta,theta1=(pai-Theta1)/2,Theta2=t2*Theta,theta2=(pai-Theta2)/2;
	return (r/sin(theta1)*sin(Theta1)+r/sin(theta2)*sin(Theta2))/sqrt(2);
}
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)scanf("%d",&n),printf("%.9lf\n",calc(n));
	return 0;
}