#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int main()
{
	int x,h,m,i;
	cin >> x >> h >> m;
	for(i=0;m%10!=7 && m/10!=7 && h%10!=7;i++)
	{
		m-=x;
		if(m<0) m+=60,h--;
		if(h<0) h+=24;
	}
	cout << i << "\n";
}