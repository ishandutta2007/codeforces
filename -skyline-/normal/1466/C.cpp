#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,t,a[100015],f[100015][4];
string s;
void u(int &x,int y){
	if(y<x)x=y;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>s;
		n=s.size();
		for(int i=3;i<=n+2;++i)a[i]=s[i-3];
		for(int i=3;i<=n+2;++i)f[i][0]=f[i][1]=f[i][2]=f[i][3]=orz;
		for(int i=3;i<=n+2;++i){
			u(f[i][1],f[i-1][0]+1);
			u(f[i][1],f[i-1][2]+1);
			u(f[i][3],f[i-1][1]+1);
			u(f[i][3],f[i-1][3]+1);
			if(a[i]!=a[i-2]&&a[i]!=a[i-1])u(f[i][0],f[i-1][0]);
			if(a[i]!=a[i-2])u(f[i][2],f[i-1][1]);
			if(a[i]!=a[i-1])u(f[i][0],f[i-1][2]);
			u(f[i][2],f[i-1][3]);
		}
		printf("%d\n",min(min(f[n+2][0],f[n+2][1]),min(f[n+2][2],f[n+2][3])));
	}
    return 0;
}