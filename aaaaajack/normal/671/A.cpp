#include<bits/stdc++.h>
#define N 100100
using namespace std;
int bx[N],by[N];
double d[2][N];
double dis(int x1,int y1,int x2,int y2){
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
double more(double d1,double d2){
	return min(d1+d2,min(d1,d2));
}
int main(){
	int x1,y1,x2,y2,x3,y3,n;
	double len=0;
	int m[2][2]={-1,-1,-1,-1};
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&bx[i],&by[i]);
		len+=dis(x3,y3,bx[i],by[i])*2;
		d[0][i]=dis(x1,y1,bx[i],by[i])-dis(x3,y3,bx[i],by[i]);
		d[1][i]=dis(x2,y2,bx[i],by[i])-dis(x3,y3,bx[i],by[i]);
		for(int j=0;j<2;j++){
			if(m[j][0]==-1||d[j][i]<d[j][m[j][0]]){
				m[j][1]=m[j][0];
				m[j][0]=i;
			}
			else if(m[j][1]==-1||d[j][i]<d[j][m[j][1]]){
				m[j][1]=i;
			}
		}
	}
	if(n==1){
		len+=min(d[0][0],d[1][0]);
	}
	else if(m[0][0]!=m[1][0]){
		len+=more(d[0][m[0][0]],d[1][m[1][0]]);
	}
	else{
		len+=min(more(d[0][m[0][0]],d[1][m[1][1]]),more(d[0][m[0][1]],d[1][m[1][0]]));
	}
	printf("%.12f\n",len);
	return 0;
}