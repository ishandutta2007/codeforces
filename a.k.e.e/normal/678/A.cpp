#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	cout<<n/k*k+k<<endl; 
	return 0;
}