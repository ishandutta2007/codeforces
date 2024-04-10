#include<cstdio>
#include<cstring>
#define N 410
using namespace std;
bool tr[N][N];
int pos[N][N],len;
char s[N],in[N],out[N],ed;
bool check(int x,int n,bool fst){
	if(x==n) return true;
	for(int i=fst?0:(in[x]-'a');i<len;i++){
		out[x]='a'+i;
		if(pos[x][x]==-1||pos[x][x]==(s[i]=='C')){
			memcpy(pos[x+1],pos[x],sizeof(int)*N);
			for(int j=0;j<n*2;j++){
				if(tr[x<<1|(s[i]=='C')][j]) pos[x+1][j>>1]=j&1;
			}
			if(check(x+1,n,fst||out[x]>in[x])) return true;
		}
	}
	return false;
}
int main(){
	scanf("%s",s);
	len=strlen(s);
	int n,m;
	bool wrong=false;
	bool allc=true,allv=true;
	for(int i=0;s[i];i++){
		if(s[i]=='C') allv=false;
		else allc=false;
	}
	int x1,x2,y1,y2;
	char c1,c2;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %c %d %c",&x1,&c1,&x2,&c2);
		x1--,x2--;
		y1=x1<<1|(c1=='C');
		y2=x2<<1|(c2=='C');
		tr[y1][y2]=true;
		tr[y2^1][y1^1]=true;
		if(allc&&c1=='C'&&c2=='V') wrong=true;
		if(allv&&c1=='V'&&c2=='C') wrong=true;
	}
	for(int i=0;i<n*2;i++){
		for(int j=0;j<n*2;j++){
			if(j==i) continue;
			for(int k=0;k<n*2;k++){
				if(k==i||k==j) continue;
				if(tr[j][i]&&tr[i][k]) tr[j][k]=true;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(tr[i<<1][i<<1|1]&&tr[i<<1|1][i<<1]){
			pos[0][i]=-2;
			wrong=true;
		}
		else if(tr[i<<1][i<<1|1]){
			pos[0][i]=1;
		}
		else if(tr[i<<1|1][i<<1]){
			pos[0][i]=0;
		}
		else{
			pos[0][i]=-1;
		}
	}
	scanf("%s",in);
	if(!wrong&&check(0,n,false)) puts(out);
	else puts("-1");
	return 0;
}