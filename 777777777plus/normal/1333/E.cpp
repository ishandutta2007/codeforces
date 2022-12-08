#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2+5;
 
/*
pair<int,int> pos[10];

bool ck1(int x,int y){
	if(pos[x].first==pos[y].first)return 1;
	if(pos[x].second==pos[y].second)return 1;
	return 0;
}

bool ck2(int x,int y){
	if(pos[x].first-pos[x].second==pos[y].first-pos[y].second)return 1;
	if(pos[x].first+pos[x].second==pos[y].first+pos[y].second)return 1;
	return 0;
}

void dfs(int x){
	static int b[20],a[5][5];
	static bool vis[20];
	if(x>16){
		int tot=0;
		bool use[20];
		b[1]=1;
		for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j)
		pos[a[i][j]=b[++tot]]={i,j};
		int p=1,cnt=0;
		memset(use,0,sizeof(use));
		use[p]=1;
		for(int i=1;i<=15;++i){
			bool flag=0;
			for(int j=1;j<=16;++j)
			if(!use[j]&&ck1(p,j)){
				use[j]=1;
				flag=1;
				p=j;
				break;
			}
			if(flag)continue;
			for(int j=1;j<=16;++j)
			if(!use[j]){
				use[j]=1;
				p=j;
				break;
			}
			cnt--;
		}
		p=1;
		memset(use,0,sizeof(use)); 
		use[p]=1;
		for(int i=1;i<=15;++i){
			bool flag=0;
			for(int j=1;j<=16;++j)
			if(!use[j]&&(ck1(p,j)||ck2(p,j))){
				use[j]=1;
				flag=1;
				p=j;
				break;
			}
			if(flag)continue;
			for(int j=1;j<=16;++j)
			if(!use[j]){
				use[j]=1;
				p=j;
				break;
			}
			cnt++;
		}
		if(cnt>0){
			for(int i=1;i<=4;++i){
				for(int j=1;j<=4;++j)cout<<a[i][j]<<" ";
				cout<<endl;
			}
			exit(0);
		} 
		return;
	}
	for(int i=2;i<=16;++i)
	if(!vis[i]){
		vis[i]=1;b[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
*/

int n,R;
int a[]={1,2,4,5,3,8,9,6,7};
int b[]={1,2,3,4,5,6,7,8,9,10,11,14,13,16,12,15}; 
int w[N][N];

int main(){
	cin>>n;
	if(n<=2){
		cout<<-1<<endl;
		return 0;
	}
	if(n&1){
		R=n-3;
		for(int i=n-2;i<=n;++i)
		for(int j=n-2;j<=n;++j){
			static int tot;
			w[i][j]=a[tot++];
		}
	}
	else{
		R=n-4;
		for(int i=n-3;i<=n;++i)
		for(int j=n-3;j<=n;++j){
			static int tot;
			w[i][j]=b[tot++];
		}
	}
	int tot=0;
	for(int i=1;i<=R;i+=2){
		for(int j=1;j<=n;++j)w[i][j]=++tot;
		for(int j=n;j>=1;--j)w[i+1][j]=++tot;
	}
	for(int j=1;j<=R;j+=2){
		for(int i=R+1;i<=n;++i)w[i][j]=++tot;
		for(int i=n;i>=R+1;--i)w[i][j+1]=++tot;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i>R&&j>R)cout<<w[i][j]+tot<<" ";
			else cout<<w[i][j]<<" ";
		}
		cout<<endl;
	}
}
/*
1 2 4
5 3 8
9 6 7
1 2 3 4
5 6 7 8
9 10 11 14
13 16 12 15
*/