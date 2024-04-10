#include <iostream>
#include <string>
using namespace std;

int main()
{
	long long k,p,ans=0,tmp,tmp2,i,ten;
	cin >> k >> p;
	for(i=1;i<=k;i++)
	{
		for(tmp=i,tmp2=0,ten=1;tmp;tmp/=10,ten*=10)
			tmp2=tmp2*10+tmp%10;
		ans=(ans+i*ten+tmp2)%p;
	}
	cout << ans << "\n";
}