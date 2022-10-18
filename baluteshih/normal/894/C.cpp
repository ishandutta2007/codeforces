#include <iostream>
#include <algorithm>
#define __ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int num[1050];

int main()
{
	long long m,i;
	cin >> m;
	for(i=0;i<m;i++)
		cin >> num[i];
	sort(num,num+m);
	for(i=1;i<m;i++)
		if(num[i]%num[0]) break;
	if(i<m) cout << "-1\n";
	else
	{
		cout << 2*m-1 << "\n";
		for(i=1,cout << num[0];i<m;i++)
			cout << " " << num[i] << " " << num[0]; 
	}
}