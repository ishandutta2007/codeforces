#include<cstdio>
#include<algorithm>
#include<map>
#include<cstdlib>
#define N 200100
using namespace std;
int x[N],rx[N];
int main(){
	int n,m,i,a,l,px,nx;
	bool dir;
	map<int,int> id;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++) scanf("%d",&x[i]),id[x[i]]=i+1,rx[i+1]=x[i];
	sort(x,x+n);
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&l);
		int lcnt=0;
		px=rx[a];
		nx=*(upper_bound(x,x+n,px+l)-1);
		dir=false;
		l-=nx-px;
		px=nx;
		while(l&&lcnt<2){
			if(dir){
				while(1){
					nx=*(upper_bound(x,x+n,px+l)-1);
					if(nx==px){
						lcnt++;
						break;
					}
					if(l>=2*(nx-px)){
						l%=2*(nx-px);
					}
					else{
						lcnt=0;
						break;
					}
				}
				l-=nx-px;
				px=nx;
				dir=false;
			}
			else{
				while(1){
					nx=*lower_bound(x,x+n,px-l);
					if(nx==px){
						lcnt++;
						break;
					}
					if(l>=2*(px-nx)){
						l%=2*(nx-px);
					}
					else{
						lcnt=0;
						break;
					}
				}
				l-=px-nx;
				px=nx;
				dir=true;
			}
		}
		printf("%d\n",id[px]);
	}
	return 0;
}