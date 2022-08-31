//CF 993A
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
const int N = 444;
const int B = 111;
int main()
{
	int i,j,l=N,r=-N,u=N,d=-N,x,y,L=N,R=-N,U=N,D=-N;
	for(i=1;i<=4;i=i+1){
		cin>>x>>y;
		l=min(l,x),r=max(r,x);
		u=min(u,y),d=max(d,y);
	}
	for(i=1;i<=4;i=i+1){
		cin>>x>>y;
		L=min(L,x+y),R=max(R,x+y);
		U=min(U,x-y),D=max(D,x-y);
	}
	for(i=l;i<=r;i=i+1)
		for(j=u;j<=d;j=j+1)
			if(L<=i+j&&i+j<=R&&U<=i-j&&i-j<=D){
				cout<<"YES";
				return 0;
			}
	cout<<"NO";
	return 0;
}