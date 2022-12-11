#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,K,tn;
int qread(){
	int nans=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		nans=nans*10+c-'0';
		c=getchar();
	}
	return nans;
}
int gcd(int x,int y){
	if(x>y) swap(x,y);
	return (y%x==0)?x:gcd(y%x,x);
}
signed main(){
//	freopen("color.in","r",stdin);
//	freopen("color.out","w",stdout);
	T=qread();
	while(T--){
		n=qread();
		m=qread();
		K=qread();
		if(K==1) printf("REBEL\n");
		else if(n==m) printf("OBEY\n");
		else{
			tn=gcd(n,m);
			n/=tn;
			m/=tn;
			if(n>m) swap(n,m);
			if(n==1){
				if(K<=m-1) printf("REBEL\n");
				else printf("OBEY\n");
			}else{
				if(K<=(int)ceil((m-1)*1.0/n)) printf("REBEL\n");
				else printf("OBEY\n");
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*

*/