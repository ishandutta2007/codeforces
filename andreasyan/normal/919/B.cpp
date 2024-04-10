#include <iostream>
using namespace std;

int k;
bool stg(int x)
{
	int res=0;
	while(x)
	{
		res+=(x%10);
		x/=10;
		if(res>10)
			break;
	}
	if(res==10)
		return true;
	return false;
}
int main()
{
	cin>>k;
	for(int i=1;;++i)
	{
		if(stg(i))
			--k;
		if(k==0)
		{
			cout<<i<<endl;
//			system("pause");
			return 0;
		}
	}
	return 0;
}