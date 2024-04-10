#include<cstdio>
#include<algorithm>
#include<map>
#define N 310
using namespace std;
map<int,int> fac;
int l[N];
int c[N];
int gcd(int a,int b){
	while(b){
		a%=b;
		swap(a,b);
	}
	return a;
}
inline void upd(int &a,int b){
	if(b<a) a=b;
}
int main(){
	int n,i,j;
	scanf("%d",&n);
	map<int,int>::iterator it;
	for(i=0;i<n;i++){
		scanf("%d",&l[i]);
		for(j=1;j*j<=l[i];j++){
			if(l[i]%j==0){
				fac[j]=1023456789;
				fac[l[i]/j]=1023456789;
			}
		}
	}
	fac[0]=0;
	for(i=0;i<n;i++){
		scanf("%d",&c[i]);
		for(it=fac.begin();it!=fac.end();++it){
			upd(fac[gcd(l[i],it->first)],it->second+c[i]);
		}
	}
	if(fac[1]==1023456789) printf("-1\n");
	else printf("%d\n",fac[1]);
	return 0;
}