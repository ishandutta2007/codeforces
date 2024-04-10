#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n,m,l,r;
	string s;
	char a,b;
	cin >> n >> m >> s;
	while(m--)
	{
		cin >> l >> r >> a >> b;
		for(l--,r--;l<=r;l++)
			if(s[l]==a) s[l]=b;
	}
	cout << s << "\n";
}