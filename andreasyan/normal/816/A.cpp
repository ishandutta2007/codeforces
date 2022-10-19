#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n,m,h;
char ch;
bool pal()
{
	int i,j;
	string k;
	k+=((h/10%10)+'0');
	k+=((h%10)+'0');
	k+=((m/10%10)+'0');
	k+=((m%10)+'0');
	for(i=0,j=k.size()-1;i<k.size(),j>=0;++i,--j)
		if(k[i]!=k[j])
			return false;
	return true;
}
int main()
{
	int i,j,k=0;
	cin>>h;
	cin>>ch;
	cin>>m;
	while(1)
	{
		if(pal())
		{
			cout<<k<<endl;
//			system("pause");
			return 0;
		}
		++k;
		++m;
		if(m%60==0)
		{
			h++;
			m=0;
		}
		if(h%24==0)
		{
			h=0;
		}
	}
	return 0;
}