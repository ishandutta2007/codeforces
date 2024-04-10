#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,xa,ya,xb,yb;
signed main(){
//	freopen("bag2.in","r",stdin);
//	freopen("bag.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>xa>>ya>>xb>>yb;int nb=0;if(xa!=xb&&ya!=yb)nb+=2;
		cout<<abs(ya-yb)+abs(xa-xb)+nb<<endl;
	}
	return 0;
}
/*

*/