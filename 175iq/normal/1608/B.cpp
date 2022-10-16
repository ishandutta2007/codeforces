#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;

int n,a,b;
int w[N];

void solve(){
	cin>>n>>a>>b;
	
	if(abs(a-b)>1||a+b+2>n){
		cout<<-1<<endl;
		return;
	}
	
	int flag=a>=b;
	int x=1,y=n;

	for(int i=1;i<=n;i++){
		if(flag){
			cout<<x<<" ";
			x++;
		}
		else{
			cout<<y<<" ";
			y--;
		}
		if(i<=a+b)flag^=1;
	}
	cout<<endl;
}

main(){
	int T;
	cin>>T;
	while(T--)solve();
}