#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long n,k,m;
int main()
{
	cin>>n>>k;
	m=(n/k)+1;
	cout<<m*k<<endl;
	return 0;
}