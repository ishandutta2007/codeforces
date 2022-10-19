#include <algorithm>
#include <string>
#include <vector>
#include <vector>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int N=2002;

int n,m;
int a[N],b[N];
bool z[N*N];
int ans;
int main()
{
	//in
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		z[a[i]]=true;
	}
	for(int i=0;i<n;++i)
	{
		cin>>b[i];
		z[b[i]]=true;
	}
	////
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			int x=a[i]^b[j];
			if(z[x])
				ans++;
		}
	}
	if(ans%2==0)
		cout<<"Karen"<<endl;
	else
		cout<<"Koyomi"<<endl;
//	system("pause");
	return 0;
}