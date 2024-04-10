#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
int A,B,S,K;
vi lp,rp;
char a[1000011],b[1000011],s[1000011];
vi Zalgo(char *p,char *t){
	int P=strlen(p),T=strlen(t),S=P+T+1,l=0,r=0;
	vi Z(S),R(T);
	memcpy(s,p,P),s[P]='$',memcpy(s+P+1,t,T);
	for(int i=1;i<S;i++){
		if(i<=r)Z[i]=min(Z[i-l],r-i);
		while(Z[i]+i<S&&s[Z[i]]==s[Z[i]+i])Z[i]++;
		if(r<Z[i]+i)l=i,r=Z[i]+i;
	}
	for(int i=0;i<T;i++)R[i]=Z[i+P+1];
	return R;
}
vector<int>v[250011];
vi pos(char *p,char *t){
	vi v(B+1,-1),z=Zalgo(p,t);
	vector<vi>ord(B+1);
	for(int i=0;i<A;i++)ord[z[i]].push_back(i);
	set<int>st;
	for(int i=B;i;i--){
		for(int j=0;j<ord[i].size();j++)st.insert(ord[i][j]);
		set<int>::iterator it=st.lower_bound(K-i);
		if(it!=st.end())v[i]=*it;
	}
	return v;
}
int main(){
	scanf("%d%d%d%s%s",&A,&B,&K,a,b);
	vi Z=Zalgo(b,a);
	for(int i=0;i<A;i++)if(Z[i]>=B){printf("Yes\n%d %d\n",min(i+1,A-2*K+1),min(i+1,A-2*K+1)+K);return 0;}
	lp=pos(b,a),reverse(a,a+A),reverse(b,b+B),rp=pos(b,a);
	for(int i=1;i<=min(B-1,K);i++){
		if(B-i>K)continue;
		if(lp[i]==-1||rp[B-i]==-1)continue;
		if(lp[i]+rp[B-i]+B-1>=A)continue;
		printf("Yes\n%d %d\n",lp[i]+i-(K-1),A-rp[B-i]-(B-i)+1);return 0;
	}
	puts("No");
	return 0;
}
/*
16 6 4
abcdcadbbbcacdca
dcadbc
18 3 4
dcdbdbadddbddbbccc
bba
6 3 2
bcbcbc
bcc
*/