#include<cstdio>
#define N 200100
using namespace std;
int a[N];
int main(){
	int pre=-1,arb=-1,d,i,n,count=0;
	bool one=false,two=false;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		if(a[i]>0){
			if(!one) one=true;
			else if(!two){
				if((a[i]-a[pre])%(i-pre)){
					count++;
					arb=-1;
				}
				else{
					d=(a[i]-a[pre])/(i-pre);
					if(arb==-1||a[i]-1LL*(i-arb)*d>0){
						two=true;
					}
					else{
						count++;
						arb=-1;
					}
				}
			}
			else{
				if(a[i]-a[pre]!=1LL*(i-pre)*d){
					count++;
					two=false;
					arb=-1;
				}
			}
			pre=i;
		}
		else{
			if(two&&a[pre]+1LL*(i-pre)*d<=0){
				count++;
				one=false;
				two=false;
				arb=i;
			}
			else if(arb==-1) arb=i; 
		}
	}
	printf("%d\n",++count);
	return 0;
}