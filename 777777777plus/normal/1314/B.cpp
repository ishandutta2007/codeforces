#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
const int INF = 0x3f3f3f3f;

void cmax(int &a,int b){
	if(b>a)a=b;
}

int n,k;
bool b[N];
struct nd{
	int f[2][2];
};

nd Solve(int l,int r){
	nd ret;
	memset(ret.f,-0x3f,sizeof(ret.f)); 
	if(l+3==r){
		static int g[4];
		for(int i=0;i<4;++i)g[i]=b[l+i];
		int res0=(g[0]|g[1])+(g[2]|g[3]);
		for(int i=0;i<2;++i)
		for(int j=2;j<4;++j){
			int res1=res0+(g[i]|g[j])+(g[i^1]|g[j^1]);
			static int g1[2],g2[2];
			g1[0]=g[i^1];g1[1]=g[j^1];
			g2[0]=g[i];g2[1]=g[j];
			for(int k=0;k<2;++k)
			for(int t=0;t<2;++t){
				cmax(ret.f[g2[t]][g2[t^1]],res1+(g2[t^1]|g1[k])+(g2[t]|g2[t^1]));
				cmax(ret.f[g2[t]][g1[k]],res1+(g2[t^1]|g1[k])+(g2[t]|g1[k]));
			}
		}
		//cout<<l<<" "<<r<<" "<<ret.f[0][0]<<" "<<ret.f[0][1]<<" "<<ret.f[1][0]<<" "<<ret.f[1][1]<<endl;;
		return ret;
	}
	int mid=l+r>>1;
	nd fl=Solve(l,mid);
	nd fr=Solve(mid+1,r);
	static int g[2][2];
	for(g[0][0]=0;g[0][0]<2;++g[0][0])
	for(g[0][1]=0;g[0][1]<2;++g[0][1])
	for(g[1][0]=0;g[1][0]<2;++g[1][0])
	for(g[1][1]=0;g[1][1]<2;++g[1][1])
	if(fl.f[g[0][0]][g[0][1]]!=-INF&&fr.f[g[1][0]][g[1][1]]!=-INF){
		int res=fl.f[g[0][0]][g[0][1]]+fr.f[g[1][0]][g[1][1]];
		res-=g[0][0]|g[0][1];
		res-=g[1][0]|g[1][1];
		res+=g[0][0]|g[1][0];
		res+=g[0][1]|g[1][1];
		for(int i=0;i<2;++i)
		for(int j=0;j<2;++j){
			cmax(ret.f[g[i][0]][g[j][1]],res+(g[i][0]|g[j][1])+(g[i^1][0]|g[j][1]));
			cmax(ret.f[g[i][0]][g[i^1][0]],res+(g[i][0]|g[i^1][0])+(g[i^1][0]|g[j][1]));
		}
	}
	//cout<<l<<" "<<r<<" "<<ret.f[0][0]<<" "<<ret.f[0][1]<<" "<<ret.f[1][0]<<" "<<ret.f[1][1]<<endl;;
	return ret;
}

int main(){
	cin>>n>>k;
	n=1<<n;
	for(int i=1,x;i<=k;++i){
		scanf("%d",&x);
		b[x]=1;
	}
	nd ret=Solve(1,n);
	int ans=0;
	for(int i=0;i<2;++i)
	for(int j=0;j<2;++j){
		ans=max(ans,ret.f[i][j]);
	}
	cout<<ans<<endl;
}