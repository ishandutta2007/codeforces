#include<cstdio>
using namespace std;
int main(){
	int w;
	int num[2]={},mv[2];
	int n,k,x,i;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		num[x&1]++;
	}
	mv[0]=(n-k)/2;
	mv[1]=(n-k+1)/2;
	if(n==k){
		w=num[1]&1;
	}
	else if(mv[0]>=num[1]){
		w=0;
	}
	else if(!(k&1)){
		if(mv[0]>=num[0]||mv[0]>=num[1]) w=0;
		else if(mv[0]+1>=num[0]&&mv[0]+1>=num[1]) w=0;
		else if((n-k)&1) w=1;
		else w=0;
	}
	else{
		if((n-k)&1){
			if(mv[0]>=num[1]) w=0;
			else w=1;
		}
		else{
			if(mv[1]>=num[0]) w=1;
			else w=0;
		}
	}
	if(w) printf("Stannis\n");
	else printf("Daenerys\n");
	return 0;
}