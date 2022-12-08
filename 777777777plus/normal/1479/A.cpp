#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n;
int a[N];

int ask(int p){
	if(p==0||p==n+1)return 1e9;
	if(a[p])return a[p];
	printf("? %d\n",p);
	fflush(stdout);
	scanf("%d",&a[p]);
	return a[p];
}

int main(){
	scanf("%d",&n);
	int l=1,r=n;
	while(r-l>=2){
		int mid=l+r>>1;
		bool f1=ask(mid)<ask(mid-1);
		bool f2=ask(mid)<ask(mid+1);
		if(f1&&f2){
			printf("! %d\n",mid);
			fflush(stdout);
			return 0;
		}
		else if(!f1&&!f2){
			r=mid-1;
		}
		else if(!f1&&f2){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	for(int mid=l;mid<=r;++mid){
		bool f1=ask(mid)<ask(mid-1);
		bool f2=ask(mid)<ask(mid+1);
		if(f1&&f2){
			printf("! %d\n",mid);
			fflush(stdout);
			return 0;
		}
	}// 7 5 6 3 4 2 1
	assert(0);
	return 0;
}