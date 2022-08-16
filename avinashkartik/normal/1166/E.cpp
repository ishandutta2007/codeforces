#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
typedef long long ll; 
using namespace std;

ll a[53][100005];
ll n,m,u,v;

int main(){
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		cin>>u;
		for(int j = 0; j < u; j++){
			cin>>v;
			a[i][v] = 1;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ll flag = 0;
			for(int k = 1; k <= m; k++){
				if(a[i][k] == 1 && a[j][k] == 1){
					flag = 1;
					break;
				}
			}
			if(flag == 0) {cout<<"impossible"<<endl; exit(0);}
		}
	}
	cout<<"possible"<<endl;
}