#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m,flag=0;
string a,b,c;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		cin>>a>>b;n=a.size();m=b.size();
		if(n>m) swap(n,m),swap(a,b);
		c=b;flag=0;
		for(i=1;i<n/__gcd(n,m);i++) c+=b;
		for(i=0;i<c.size();i++){
			if(c[i]!=a[i%n]){flag=1;break;}
		}
		if(flag) printf("-1\n");
		else cout<<c<<endl;
	}
}