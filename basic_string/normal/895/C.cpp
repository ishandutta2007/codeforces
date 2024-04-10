#include<bits/stdc++.h>
using namespace std;
int p[] = { 2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47 , 53 , 59 , 61 , 67 } ;
int c[21];
const int P=1e9+7;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,i,j,x,y,w=1;
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>x,y=0;
		for(j=18;~j;--j){
			while(x%p[j]==0)x/=p[j],y^=1<<j;
		}
		for(j=18;~j;--j)if(y>>j&1){
			if(!c[j]){c[j]=y;break;}
			y^=c[j];
		}
	}
	for(j=18;~j;--j)if(c[j])--n;
	while(n--)w=w*2%P;
	cout<<(w-1+P)%P;
	return 0;
}