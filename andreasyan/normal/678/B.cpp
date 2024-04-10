#include <iostream>
using namespace std;

int n,m;
int main()
{
	cin>>n;
	for(int i=n;;++i)
	{
		if((i%4==0 && i%100!=0) || (i%400==0 && i%100==0))
		{
//			m=(m+366)%7;
			m+=2;
			m%=7;
		}
		else
		{
//			m=(m+365)%7;
			m+=1;
			m%=7;
		}
		++i;
		if((i%4==0 && i%100!=0) || (i%400==0 && i%100==0))
		{
			if(((n%4==0 && n%100!=0) || (n%400==0 && n%100==0)) && m==0)
			{
				cout<<i<<endl;
				break;
			}
		}
		else
		{
			if(!((n%4==0 && n%100!=0) || (n%400==0 && n%100==0)) && m==0)
			{
				cout<<i<<endl;
				break;
			}
		}
		--i;
		//
	}
	return 0;
}