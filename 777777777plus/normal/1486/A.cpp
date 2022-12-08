#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T;
int n,h[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;++i)cin>>h[i];
		ll a=0,b=0;
		bool flag=1;
		for(int i=0;i<n;++i){
			a+=i;
			b+=h[i];
			if(a>b)flag=0;
		}
		puts(flag?"yes":"no");
	}
}