#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main(){
	int n,m,h,x,y,px,py,d,l;
	bool first=true,wrong=false;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&x,&y);
		if(first){
			h=x-1+y;
			first=false;
			px=x;
			py=y;
		}
		else{
			d=x-px;
			l=abs(y-py);
			if(d<l) wrong=true;
			else h=max(h,max(y,py)+(d-l)/2);
			px=x;
			py=y;
		}
	}
	h=max(h,py+n-px);
	if(!wrong) printf("%d\n",h);
	else printf("IMPOSSIBLE\n");
	return 0;
}