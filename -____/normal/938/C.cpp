//CF 938C
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
LL F(int x,int y){
	y=x/y;
	return (LL)x*x-(LL)y*y;
}
int main()
{
	int T,x,i,j,r,c,u;
	cin>>T;
	while(T--){
		cin>>x;
		if(!x){
			cout<<"1 1\n";
			continue;
		}
		u=1;
		for(i=1;i*i<x&&u;i=i+1){
			if(x%i)
				continue;
			j=x/i;
			if(j%2!=i%2)
				continue;
			r=(j+i)>>1;
			c=(j-i)>>1;
			if(F(r,r/c)==x)
				cout<<r<<' '<<r/c<<endl,u=0;
			else{
				if(F(r,r/c+1)==x)
					cout<<r<<' '<<r/c+1<<endl,u=0;
			}
		}
		if(u)
			cout<<"-1\n";
	}
	return 0;
}