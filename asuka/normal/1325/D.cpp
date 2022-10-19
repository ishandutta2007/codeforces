#include<bits/stdc++.h>
#define ll long long
#define N
using namespace std;
ll u,v;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>u>>v;
	if(u > v||(u%2!=v%2)){
		puts("-1");
	}else{
		if(u+v==0){
			cout << 0;
			return 0;
		}
		if(u == v){
			cout << 1 << endl;
			cout << u << endl;
			return 0;
		}
		if((u&((v-u)/2))==0){
			cout << 2 << endl;
			cout << u + (v-u)/2 << ' ' << (v-u)/2;
			return 0;
		}
		cout << 3 << endl;
		cout << u << ' ' << (v-u)/2 << ' ' << (v-u)/2;
	}
	return 0;
}