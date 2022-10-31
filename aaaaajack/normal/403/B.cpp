#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
bool isprime[40000];
int prime[40000];
int pcnt=0;
int beauty(set<int>& bad,int n){
	int i,count=0;
	for(i=0;i<pcnt;i++){
		while(n%prime[i]==0){
			n/=prime[i];
			if(bad.count(prime[i])) count--;
			else count++;
		}
	}
	if(n>1){
		if(bad.count(n)) count--;
		else count++;
	}
	return count;
}
int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}
int main(){
	memset(isprime,-1,sizeof(isprime));
	int i,j,n,m,a[5010],b[5010],ans=0,change=0,x,pre;
	set<int> bad;
	for(i=2;i<40000;i++){
		if(isprime[i]){
			prime[pcnt++]=i;
			for(j=2;i*j<40000;j++){
				isprime[2*i]=false;
			}
		}
	}
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<m;i++){
		scanf("%d",&x);
		bad.insert(x);
	}
	pre=a[0];
	for(i=0;i<n;i++){
		ans+=beauty(bad,a[i]);
		pre=gcd(a[i],pre);
		b[i]=beauty(bad,pre);
	}
	for(i=n-1;i>=0;i--){
		if(b[i]<change) change=b[i];
		ans-=change;
	}
	printf("%d\n",ans);
	return 0;
}