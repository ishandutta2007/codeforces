#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;

int T;
int v[N];

int main(){
	for(int i=1;i<N;++i)v[i]=v[i-1]^i;
	cin>>T;
	while(T--){
		int a,b;
		cin>>a>>b;
		b^=v[a-1];
		if(b==0)cout<<a<<endl;
		else if(b==a)cout<<a+2<<endl;
		else cout<<a+1<<endl;
	}
}