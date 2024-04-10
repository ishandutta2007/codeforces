//CF1063A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
char c[N];
int n;
int main()
{
	int i;
	cin>>n>>c;
	sort(c,c+n);
	for(i=0;i<n;i=i+1)
		cout<<c[i];
	return 0;
}