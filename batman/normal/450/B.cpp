#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define MOD (1000*1000*1000+7)

ll a,b,n,ans;
int main() {
	cin>>a>>b>>n;
	switch(n%6)
	{
		case 1:
			ans=a;
			break;
		case 2:
			ans=b;
			break;
		case 3:
			ans=b-a;
			break;
		case 4:
			ans=-a;
			break;
		case 5:
			ans=-b;
			break;
		case 0:
			ans=a-b;
			break;					
	}
	ans%=MOD;
	if(ans<0)
		ans+=MOD;
	cout<<ans;						
	return 0;
}