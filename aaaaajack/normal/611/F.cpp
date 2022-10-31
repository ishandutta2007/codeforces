#include<cstdio>
#include<vector>
#define N 500100
#define Q 1000000007
using namespace std;
long long pos[4][N];
int l[4];
char s[N];
vector<int> can,cyc;
int main(){
	int n,h,w;
	long long ans=0;
	scanf("%d%d%d",&n,&h,&w);
	int mh=0,mv=0;
	scanf("%s",s+1);
	for(int i=1;i<=n&&h&&w;i++){
		if(s[i]=='R'){
			mh++;
			if(mh>l[0]){
				pos[0][++l[0]]=i;
				ans+=1LL*h*i%Q;
				w--;
			}
		}
		else if(s[i]=='L'){
			mh--;
			if(-mh>l[1]){
				pos[1][++l[1]]=i;
				ans+=1LL*h*i%Q;
				w--;
			}
		}
		else if(s[i]=='U'){
			mv++;
			if(mv>l[2]){
				pos[2][++l[2]]=i;
				ans+=1LL*w*i%Q;
				h--;
			}
		}
		else{
			mv--;
			if(-mv>l[3]){
				pos[3][++l[3]]=i;
				ans+=1LL*w*i%Q;
				h--;
			}
		}
		ans%=Q;
	}
	if(h&&w&&!mh&&!mv){
		puts("-1");
	}
	else{
		if(mh>0) can.push_back(0),cyc.push_back(mh);
		if(mh<0) can.push_back(1),cyc.push_back(-mh);
		if(mv>0) can.push_back(2),cyc.push_back(mv);
		if(mv<0) can.push_back(3),cyc.push_back(-mv);
		while(h&&w){
			int ch=-1;
			long long to;
			for(int i=0;i<can.size();i++){
				long long tmp=pos[can[i]][l[can[i]]+1-cyc[i]]+n;
				if(ch==-1||tmp<to){
					ch=can[i];
					to=tmp;
				}
			}
			pos[ch][++l[ch]]=to;
			if(ch<2){
				ans+=h*to%Q;
				w--;
			}
			else{
				ans+=w*to%Q;
				h--;
			}
			ans%=Q;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}