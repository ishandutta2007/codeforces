#include<bits/stdc++.h>
#define N 1000100
using namespace std;
int a[N],g[N];
int main(){
	//grey code
	for(int i=1;i<20;i++){
		int msk=(1<<i)-1;
		for(int j=(1<<i-1);j<(1<<i);j++){
			g[j]=(1<<i-1)|g[j^msk];
		}
	}
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=19;i>=0;i--){
		vector<int> v,piv;
		for(int j=0;j<n;j++){
			if(a[j]>=(1<<i)) continue;
			int x=a[j];
			for(int k=0;k<v.size();k++){
				if(x&(piv[k]&-piv[k])) x^=piv[k];
			}
			if(x>0){
				v.push_back(a[j]);
				piv.push_back(x);
			}
		}
		if(v.size()==i){
			printf("%d\n",i);
			for(int j=0;j<(1<<i);j++){
				int x=0;
				for(int k=0;k<i;k++){
					if(g[j]&(1<<k)) x^=v[k];
				}
				printf("%d ",x);
			}
			puts("");
			break;
		}
	}
	return 0;
}