#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)

int main(){
	int n,prev=0,next,l=0,ans = 0;
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%d",&next);
		if(next < prev){
			ans = max(ans,l);
			l = 0;
		}
		++l;
		prev = next;
	}
	printf("%d\n",max(ans,l));
}