#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
int n,k;

void request(int x){
	printf("! %d\n",x);
	fflush(stdout);
}

int query(int l1,int r1,int l2,int r2){
	printf("? %d %d\n",r1-l1+1,r2-l2+1);
	for(int i=l1;i<=r1;++i)printf("%d ",i);
	printf("\n"); 
	for(int i=l2;i<=r2;++i)printf("%d ",i);
	printf("\n");
	fflush(stdout);
	char s[10];
	scanf("%s",s);
	if(s[0]=='F')return 0;
	if(s[0]=='S')return 2;
	if(s[0]=='E')return 1;
	assert(s[0]!='W');
}

void Solve(){
	for(int i=1,x;i<=25;++i){
		x=rand()%(n-1)+2;
		if(query(1,1,x,x)==2){
			request(1);
			return;
		}
	}
	int k=1,l,r=1;
	for(int i=1;i<=10;++i){
		r=min(k<<1,n);
		if(query(1,r-k,k+1,r)==0){
			l=k+1;
			break;
		}
		k<<=1;
		if(r==n)break;
	}
	while(l!=r){
		int mid=l+r>>1;
		if(query(1,mid-l+1,l,mid)==0)r=mid;
		else l=mid+1;
	}
	request(l);
}

int main(){
	srand(time(NULL));
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		Solve();
	}
}