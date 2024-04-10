#include <iostream>
#include <fstream>
#include <algorithm>

#define M 21
#define mod 1000000007

using namespace std;

ofstream fout("output.txt");

int n,p[M];
long long ans=0;

void pre(void){
	p[0]=1;
	for (int i=1; i<M; ++i)
	p[i]=p[i-1]<<1;
}

void dfs(int m1, int m2, int k){
	if (k==n){
		ans++;
		return;
	}
	for (int i=0; i<n; ++i)
	if ((m1&p[i])==0 && (m2&p[(i+k)%n])==0)
	dfs(m1|p[i],m2|p[(i+k)%n],k+1);
}

int a[]={0,1, 0, 18, 0, 1800, 0, 670320, 0, 734832000, 0, 890786230, 0, 695720788, 0, 150347555, 0};


int main()
{
	cin>>n;
	cout<<a[n]<<"\n";
	return 0;
}