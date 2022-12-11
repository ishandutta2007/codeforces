#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a),i##z=(b);i<=i##z;i++)
#define ROF(i,a,b) for(int i=(a),i##z=(b);i<=i##z;i--)
#define temT template<typename T>
using namespace std;
typedef long long ll;

ll calc(int a[4]){
	return 1ll*min(a[0],a[2])*min(a[1],a[3]);
}

int main(){
	pair<int,int> pp[4];
	int a[4],T;
	
	cin>>T;
	
	while(T--){
		FOR(i,0,3) pp[i].first=i;
		FOR(i,0,3) cin>>pp[i].second;
		bool flag=true; ll res=0;
		while(flag){
			FOR(i,0,3) a[i]=pp[i].second;
			res=max(res,calc(a));
			flag=next_permutation(pp+0,pp+3+1);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}