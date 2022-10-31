#include<bits/stdc++.h>
#define N 210
using namespace std;
string pf[N],s[N];
int a[N];
long long sc[50][N][N];
long long tmx[N],nmx[N];
long long nsc[N];
map<string,int> match;
map<string,int> id;
int main(){
	memset(sc,-1,sizeof(sc));
	memset(tmx,-1,sizeof(tmx));
	tmx[0]=0;
	int n,cnt=0;
	long long l;
	scanf("%d%I64d",&n,&l);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		cin>>s[i];
		match[s[i]]+=a[i];
		string tmp;
		for(int j=0;j<s[i].size();j++){
			tmp.push_back(s[i][j]);
			if(!id.count(tmp)) pf[++cnt]=tmp,id[tmp]=cnt;
		}
	}
	for(int i=1;i<=cnt;i++){
		string tmp = pf[i];
		while(!tmp.empty()){
			if(match.count(tmp)) nsc[i]+=match[tmp];
			tmp=tmp.substr(1);
		}
	}
	for(int i=0;i<=cnt;i++){
		for(char c='a';c<='z';c++){
			string tmp=pf[i];
			tmp.push_back(c);
			while(!tmp.empty()){
				if(id.count(tmp)){
					sc[0][i][id[tmp]]=nsc[id[tmp]];
					break;
				}
				tmp=tmp.substr(1);
			}
			if(tmp.empty()) sc[0][i][0]=0;
		}
	}
	for(int i=0;i<49;i++){
		if(l&(1LL<<i)){
			memset(nmx,-1,sizeof(nmx));
			for(int j=0;j<=cnt;j++){
				if(tmx[j]<0) continue;
				for(int k=0;k<=cnt;k++){
					if(sc[i][j][k]>=0){
						nmx[k]=max(nmx[k],tmx[j]+sc[i][j][k]);
					}
				}
			}
			for(int j=0;j<=cnt;j++) tmx[j]=nmx[j];
		}
		for(int j=0;j<=cnt;j++){
			for(int k=0;k<=cnt;k++){
				if(sc[i][j][k]<0) continue;
				for(int l=0;l<=cnt;l++){
					if(sc[i][k][l]>=0){
						sc[i+1][j][l]=max(sc[i+1][j][l],sc[i][j][k]+sc[i][k][l]);
					}
				}
			}
		}
	}
	long long ans=0;
	for(int i=0;i<=cnt;i++){
		ans=max(ans,tmx[i]);
	}
	printf("%I64d\n",ans);
	return 0;
}