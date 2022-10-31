#include<cstdio>
using namespace std;
int main(){
	long long w,m,k,ten,count=0;
	int dig=0;
	scanf("%I64d %I64d %I64d",&w,&m,&k);
	w/=k;
	ten=1;
	while(w>0){
		while(m>=ten){
			ten*=10;
			dig++;
		}
		if(w>=dig*(ten-m)){
			w-=dig*(ten-m);
			count+=(ten-m);
			m=ten;
		}
		else{
			count+=w/dig;
			w=0;
		}
	}
	printf("%I64d\n",count);
	return 0;
}