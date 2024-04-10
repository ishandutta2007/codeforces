#include<bits/stdc++.h>
#include<set>
using namespace std;
int T,n,m,K,np,nq,mi,mx;
string s;
vector<int> ve[90001];
bool chk(){
	for(int i=1;i<s.size();i++) if(s[i-1]=='R'&&s[i]=='L') return 1;
	return 0;
}
signed main(){
	cin>>n>>K;
	cin>>s;
	mi=1;
	for(mi=1;chk();mi++){
		for(int i=1;i<s.size();i++){
			if(s[i-1]=='R'&&s[i]=='L'){
				ve[mi].push_back(i);
				mx++;
			}
		}
		for(int i=0;i<ve[mi].size();i++){
			s[ve[mi][i]-1]='L';
			s[ve[mi][i]]='R';
		}
	}
	
	mi--;
//	for(int i=1;i<=mi;i++){
//		for(int j=0;j<ve[i].size();j++){
//			printf("%d ",ve[i][j]);
//		}
//		printf("\n");
//	}
	if(K<mi||K>mx) printf("-1\n");
	else{
		np=1;
		nq=0;
		int nmi=mi;
		while(nmi<K){
			if(ve[np].size()==1){
				printf("1 %d\n",ve[np][0]);
				np++;
			}else{
				printf("1 %d\n",ve[np][nq]);
				nq++;
				if(nq>=ve[np].size()-1){
					printf("1 %d\n",ve[np][nq]);
					np++;
					nq=0;
				}
				nmi++;
			}
			
		}
		for(int i=np;i<=mi;i++){
			printf("%d ",ve[i].size()-nq);
			for(int j=nq;j<ve[i].size();j++){
				printf("%d ",ve[i][j]);
			}
			printf("\n");
			nq=0;
		}
	}
	return 0;
}
/*
10 13
RLLRLRRLRL
*/