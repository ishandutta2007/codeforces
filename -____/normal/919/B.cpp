//CF 919B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
int cal(int x){
	if(!x)
		return 0;
	return cal(x/10)+x%10;
}
int main()
{
	int n,i;
	cin>>n;
	for(i=1;n;)
		if(cal(++i)==10)
			n--;
	cout<<i;
	return 0;
}