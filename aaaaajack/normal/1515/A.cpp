#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,x;
		int a[200],s=0;
		scanf("%d%d",&n,&x);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			s+=a[i];
		}
		if(s==x) puts("NO");
		else{
			puts("YES");
			s=0;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(a[j]&&s+a[j]!=x){
						s+=a[j];
						printf("%d ",a[j]);
						a[j]=0;
						break;
					}
				}
			}
			puts("");
		}
	}
	return 0;
}