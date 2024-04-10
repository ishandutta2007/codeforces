#include<bits/stdc++.h>
#define N 200100
using namespace std;
int a[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,l,r,c,pos=0,neg=0;
		scanf("%d%d%d",&n,&l,&r);
		for(int i=0;i<n;i++){
			scanf("%d",&c);
			if(i<l) a[c-1]++;
			else a[c-1]--;
		}
		for(int i=0;i<n;i++){
			if(a[i]>0) pos+=a[i];
			else neg-=a[i];
		}
		if(neg>pos){
			for(int i=0;i<n;i++) a[i]=-a[i];
			swap(pos,neg);
		}
		int c1=0;
		for(int i=0;i<n;i++) if(a[i]>0 && (a[i]&1)) c1++;
		for(int i=0;i<n;i++) a[i]=0;
		printf("%d\n",neg+(pos-neg)/2+max(c1-neg,0)/2);
	}
	return 0;
}