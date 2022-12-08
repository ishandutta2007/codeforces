#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+5;

int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
} 

int n,m,p;
int a[N],b[N];

bool check(int t){
	int c=0;
	for(int i=0;i<n;++i)(c+=1ll*a[i]*b[t-i]%p)%=p;
	return c!=0;
}

int main(){
	n=read();m=read();p=read();
	for(int i=0;i<n;++i)a[i]=read();
	for(int i=0;i<m;++i)b[i]=read();
	int c1=0,c2=0;
	for(int i=0;i<n;++i)
	if(a[i]%p){
		c1=i;
		break;
	}
	for(int i=0;i<m;++i)
	if(b[i]%p){
		c2=i;
		break;
	}
	cout<<c1+c2<<endl;
}