#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int n,m;
int main()
{
	int s, v1, v2, t1, t2;
	cin>>s>>v1>>v2>>t1>>t2;
	n=v1*s+2*t1;
	m=v2*s+2*t2;
	if(n<m)
		cout<<"First"<<endl;
	if(n>m)
		cout<<"Second"<<endl;
	if(n==m)
		cout<<"Friendship"<<endl;
//	system("pause");
	return 0;
}