#include<bits/stdc++.h>
using namespace std;
int T,n,num[300100];
bool cs(){
	for(int i=1;i<n;i++)if(num[i]!=num[0])return false;
	return true;
}
int ad(){
	for(int i=0;i<n;i++)if(num[i]==num[(i+1)%n])return i;
	return -1;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&num[i]);
		if(cs()){
			puts("1");
			for(int i=0;i<n;i++)printf("1 ");
			puts("");continue;
		}
		if(n&1){
			int k=ad();
			if(k==-1){
				puts("3");
				printf("1 ");
				for(int i=1;i<n;i++)printf("%d ",(i&1)+2);
				puts("");
			}else{
				puts("2");
				if(k==n-1){printf("1 ");for(int i=1;i<n-1;i++)printf("%d ",(i&1)+1);printf("1 ");puts("");continue;}
				for(int i=0;i<k;i++)printf("%d ",1+((i&1)!=(k&1)));
				printf("1 1 ");
				for(int i=k+2;i<n;i++)printf("%d ",1+((i&1)==(k&1)));
				puts("");
			}
		}else{
			puts("2");
			for(int i=0;i<n;i++)printf("%d ",(i&1)+1);
			puts("");
		}
	}
	return 0;
}