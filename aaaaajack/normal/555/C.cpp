#include<cstdio>
#include<map>
using namespace std;
int main(){
	map<int,int> xmp,ymp;
	xmp[0]=ymp[0]=0;
	map<int,int>::iterator xit,yit;
	int n,q,x,y,tmp;
	char dir;
	scanf("%d%d",&n,&q);
	while(q--){
		scanf("%d%d %c",&x,&y,&dir);
		xit=xmp.upper_bound(x);
		yit=ymp.upper_bound(y);
		if(dir=='U'){
			yit--;
			if(xmp.count(x)) printf("0\n");
			else if(xit!=xmp.end()){
				tmp=yit->first>n+1-xit->first?yit->first:xit->second;
				printf("%d\n",y-tmp);
				xmp[x]=tmp;
			}
			else{
				tmp=yit->first;
				printf("%d\n",y-tmp);
				xmp[x]=tmp;
			}
		}
		else{
			xit--;
			if(ymp.count(y)) printf("0\n");
			else if(yit!=ymp.end()){
				tmp=xit->first>n+1-yit->first?xit->first:yit->second;
				printf("%d\n",x-tmp);
				ymp[y]=tmp;
			}
			else{
				tmp=xit->first;
				printf("%d\n",x-tmp);
				ymp[y]=tmp;
			}
		}
	}
	return 0;
}