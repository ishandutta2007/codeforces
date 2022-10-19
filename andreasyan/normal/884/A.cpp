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
const int N=102;

int n,t;
int a[N];
int main()
{
	cin>>n>>t;
	for(int i=0;i<n;++i)
		cin>>a[i];
	for(int i=0;i<n;++i)
	{
		t-=(86400-a[i]);
		if(t<=0)
		{
			cout<<i+1<<endl;
			break;
		}
	}
	return 0;
}