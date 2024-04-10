#include<cstdio>
#include<cstdlib>
#include<map>
#include<cstring>
using namespace std;
void modify(int bd[6][6],int a[6],int b[6],int dir,int x){
	int cnt=0,next,i;
	if(dir){
		if(!b[x]) return;
		for(i=1;i<=5;i++){
			if(bd[i][x]) cnt++,next=i;
		}
		if(cnt==1){
			bd[next][x]=0;
			modify(bd,a,b,1-dir,next);
		}
	}
	else{
		if(!a[x]) return;
		for(i=1;i<=5;i++){
			if(bd[x][i]) cnt++,next=i;
		}
		if(cnt==1){
			bd[x][next]=0;
			modify(bd,a,b,1-dir,next);
		}
	}
}
int main(){
	char tp;
	map<char,int> id;
	char col[6]={0,'R','G','B','Y','W'};
	int num,n,i,j,cnt,ans,k;
	int flag;
	int ori[6][6]={0},temp[6][6],a[6],b[6];
	for(i=1;i<=5;i++) id.insert(make_pair(col[i],i));
	ans=25;
	scanf("%d",&n);
	for(i=0;i<n;i++){
	    scanf(" %c%d",&tp,&num);
		ori[id[tp]][num]=1;
	}
	for(i=0;i<1024;i++){
		cnt=0;
		memcpy(temp,ori,sizeof(ori));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(j=0;j<10;j++){
			if(i&(1<<j)){
				cnt++;
				if(j<5){
					a[j+1]=1;
					for(k=1;k<=5;k++){
						if(b[k]){
							temp[j+1][k]=0;
						}
					}
				}
				else{
					b[j-4]=1;
					for(k=1;k<=5;k++){
						if(a[k]){
							temp[k][j-4]=0;
						}
					}
				}
				for(k=0;k<10;k++){
					modify(temp,a,b,k/5,k%5+1);
				}
			}
		}
		flag=0;
		for(j=0;j<25;j++){
			if(temp[j/5+1][j%5+1]) flag++;
		}
		if(flag<=1&&cnt<ans) ans=cnt;
	}
	printf("%d\n",ans);
	return 0;
}