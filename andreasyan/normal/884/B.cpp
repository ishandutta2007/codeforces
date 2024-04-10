#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <list>
using namespace std;
const int N=100003;

int n,x;
long long m;
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=0;i<n;++i)
	{
		int y;
		scanf("%d",&y);
		m+=y;
	}
	if(x==(n-1)+m)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}