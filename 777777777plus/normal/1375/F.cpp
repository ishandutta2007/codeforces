#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x;
ll a,b,c;


int main(){
	cin>>a>>b>>c;
	printf("First\n");
	printf("%lld\n",a+b+c);
	fflush(stdout);
	int t;
	scanf("%d",&t);
	if(t==1){
		x=a+a+b+c;
		printf("%lld\n",2*x-b-c);
		fflush(stdout);
		scanf("%d",&t);
		if(t==2){
			b+=2*x-b-c;
			printf("%lld\n",x-c);
			fflush(stdout);
			scanf("%d",&t);
			assert(t==0);
			return 0;
		}
		if(t==3){
			c+=2*x-b-c;
			printf("%lld\n",x-b);
			fflush(stdout);
			scanf("%d",&t);
			assert(t==0);
			return 0;
		}
	} 
	if(t==2){
		x=b+a+b+c;
		printf("%lld\n",2*x-a-c);
		fflush(stdout);
		scanf("%d",&t);
		if(t==1){
			a+=2*x-a-c;
			printf("%lld\n",x-c);
			fflush(stdout);
			scanf("%d",&t);
			assert(t==0);
			return 0;
		}
		if(t==3){
			c+=2*x-a-c;
			printf("%lld\n",x-a);
			fflush(stdout);
			scanf("%d",&t);
			assert(t==0);
			return 0;
		}
	} 
	if(t==3){
		x=c+a+b+c;
		printf("%lld\n",2*x-a-b);
		fflush(stdout);
		scanf("%d",&t);
		if(t==2){
			b+=2*x-a-b;
			printf("%lld\n",x-a);
			fflush(stdout);
			scanf("%d",&t);
			assert(t==0);
			return 0;
		}
		if(t==1){
			a+=2*x-a-b;
			printf("%lld\n",x-b);
			fflush(stdout);
			scanf("%d",&t);
			assert(t==0);
			return 0;
		}
	} 
}