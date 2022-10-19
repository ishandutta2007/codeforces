#include <iostream>
#include <string>
using namespace std;

int k;
string n;
int a[11];
int ans;
int gum;
int m;
int main()
{
	cin>>k>>n;
	m=n.size();
	for(int i=0;i<m;++i)
	{
		a[n[i]-'0']++;
		gum+=(n[i]-'0');
	}
	for(int i=0;i<10;++i)
	{
		while(a[i])
		{
			if(gum>=k)
			{
				cout<<ans<<endl;
//				system("pause");
				return 0;
			}
			gum-=i;
			gum+=9;
			++ans;
			--a[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}