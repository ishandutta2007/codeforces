#include<bits/stdc++.h>
using namespace std;
struct apple{
	int a,wz;
	bool operator<(const apple &other)const{
		return a<other.a;
	}
}e[70005];
int fj[70005],sf[70005];
bitset<70005>K[21005],F[105];
vector<int>g[70005];
int A[70005];
void fin(int x,int s){
	if(s==0||x==0)return;
	int ll=0;
	for(int i=x-1;i>=0;--i)if(!K[i][s]){
		ll=i+1;
		break;
	}
	sf[ll]=1,fin(ll-1,s-e[ll].a);
}
signed main(){
	int n,s;
	cin>>n>>s;
	for(int i=1;i<=n;++i)scanf("%d",&e[i].a),e[i].wz=i;
	sort(e+1,e+n+1);
	if(s<e[n].a){
		printf("-1\n");
		return 0;
	}
	s-=e[n].a,sf[n]=1;
	if(n<=100){
		K[0].set(0);
		for(int i=1;i<n;++i)K[i]=K[i-1]|(K[i-1]<<e[i].a);
		if(!K[n-1][s]){
			printf("-1\n");
			return 0;
		}
		fin(n-1,s);
	}else{
		int T=7,xd=(n-2)/T;
		for(int i=1;i<=T;++i)fj[i]=(i-1)*xd+1;
		fj[T+1]=n+1;
		F[0].set(0);
		for(int i=1;i<=T;++i){
			F[i]=F[i-1];
			for(int j=fj[i];j<fj[i+1];++j)F[i]|=F[i]<<e[j].a;
		}
		if(!F[T][s]){
			printf("-1\n");
			return 0;
		}
		int lst=T;
		K[0]=F[T-1];
		for(int i=1;i<=fj[T+1]-fj[T];++i)
			K[i]=K[i-1]|(K[i-1]<<e[i+fj[T]-1].a);
		for(int i=n;i>=1&&s;--i){
			if(i==1){
				sf[i]=1;
				break;
			}
			if(i==fj[lst]){
				K[0]=F[lst-2];
				for(int j=1;j<=fj[lst]-fj[lst-1];++j){
					K[j]=K[j-1]|(K[j-1]<<e[j+fj[lst-1]-1].a);
				}
				--lst;
			}
			if(!K[i-fj[lst]][s]){
				s-=e[i].a,sf[i]=1;
			}
		}
	}
	A[e[n].wz]=e[n].a;
	for(int i=n-1;i>=1;--i){
		A[e[i].wz]=e[i].a;
		if(!sf[i]){
			g[e[i+1].wz].emplace_back(e[i].wz);
			A[e[i+1].wz]-=e[i].a;
		}
	}
	for(int i=1;i<=n;++i){
		printf("%d %d",A[i],(signed)g[i].size());
		for(auto cu:g[i])printf(" %d",cu);
		printf("\n");
	}
	return (signed)0;
}

//qwq