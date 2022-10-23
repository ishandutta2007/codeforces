#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,p,q,x,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&x);
		if(x==p){
			if(q!=x)++ans;
			q=x;
			continue;
		}
		if(x==q){
			if(p!=x)++ans;
			p=x;
			continue;
		}
		if(p!=q)q=-1;
		p=x;
		++ans;
	}
	printf("%d\n",ans);
	
    return 0;
}