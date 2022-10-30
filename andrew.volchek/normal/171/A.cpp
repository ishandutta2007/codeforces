#include <iostream>

using namespace std;

#define ull unsigned long long

int main()
{
	ull a,b;
	cin >> a >> b;
	int C[11];
	int pos = 0;
	if(b==0)
	{
		cout << a+b;
		return 0;
	}
	while(b)
	{
		C[pos] = b%10;
		pos++;
		b/=10;
	}
	for(int i=0;i<pos;i++)
		b = b*10 + C[i];

	cout << a+b;
	
	return 0;
}