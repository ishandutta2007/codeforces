#include<cstdio>
using namespace std;
int mx[6]={2,1,-1,-2,-1,1},my[6]={0,-1,-1,0,1,1};
int main(){
	int px,py,nx,ny,l,ans=0;
	px=py=0;
	for(int i=0;i<6;i++){
		scanf("%d",&l);
		nx=px+mx[i]*l;
		ny=py+my[i]*l;
		ans+=nx*py-ny*px;
		px=nx;
		py=ny;
	}
	printf("%d\n",ans/2);
	return 0;
}