#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n;

int ask(int l,int r){
	int p;
	printf("? %d %d\n",l,r);
	fflush(stdout);
	scanf("%d",&p);
	return p;
}

int main(){
	scanf("%d",&n);
	int p=ask(1,n);
	if(p!=1&&ask(1,p)==p){
		int l=1,r=p-1;
		while(l!=r){
			int mid=l+r+1>>1;
			if(ask(mid,p)==p)l=mid;
			else r=mid-1;
		}
		printf("! %d\n",l);
		fflush(stdout);
	}
	else{
		int l=p+1,r=n;
		while(l!=r){
			int mid=l+r>>1;
			if(ask(p,mid)==p)r=mid;
			else l=mid+1;
		}
		printf("! %d\n",l);
		fflush(stdout);
	}
}