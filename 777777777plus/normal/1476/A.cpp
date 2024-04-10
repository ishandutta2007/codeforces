#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')ch=='-'?f=-1:0,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}

int T;
ll n,k;

int main(){
	T=read();
	while(T--){
		n=read();k=read();
		if(n>k){
			if(n%k==0)cout<<1<<endl;
			else cout<<2<<endl;
		}
		else cout<<(k+n-1)/n<<endl;
	}
}