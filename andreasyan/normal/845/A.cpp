#include <iostream>
#include <algorithm>
using namespace std;
const int N=501;

int n;
int a[N];
int main()
{
	cin>>n;
	for(int i=0;i<n*2;++i)
		cin>>a[i];
	sort(a,a+n*2);
	if(a[n]>a[n-1])
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
//	system("pause");
	return 0;
}