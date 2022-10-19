#include <iostream>
using namespace std;

char a[102];
int main()
{
	int i, j, k, n, m;
	cin >> a;
	n = strlen(a);
	for(i=0;i<n;i++)
		if(a[i]=='H' || a[i]=='Q' || a[i]=='9')
		{
			cout << "YES" << endl;
			return 0;
		}
	cout << "NO" << endl;
	return 0;
}