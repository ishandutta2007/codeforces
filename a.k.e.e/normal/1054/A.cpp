#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAXN=1005,MOD=1000000007;

int x,y,z,t1,t2,t3;

int main()
{
	cin>>x>>y>>z>>t1>>t2>>t3;
	int a=abs(x-y)*t1;
	int b=abs(x-z)*t2+abs(x-y)*t2+t3*3;
	if(b<=a)cout<<"YES";
	else cout<<"NO";
	return 0;
}