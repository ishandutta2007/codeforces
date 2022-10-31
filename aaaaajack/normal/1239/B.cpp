#include<bits/stdc++.h>
#define N 300100
using namespace std;
char s[N];
int psum[N];
int calc(int i,int j, int n){
	swap(s[i],s[j]);
	int p=0,mn=0,mc=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='(') p++;
		else p--;
		if(p<mn){
			mn=p;
			mc=1;
		}
		else if(p==mn) mc++;
	}
	swap(s[i],s[j]);
	return mc;
}
int get_left(int n,int x){
	for(int i=1;i<=n;i++){
		if(psum[i]==x) return i;
	}
}
int get_right(int n,int x){
	for(int i=n;i>=1;i--){
		if(psum[i]==x) return i+1;
	}
}
int main(){
	int n,mn=0;
	scanf("%d %s",&n,s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='(')  psum[i]=psum[i-1]+1;
		else psum[i]=psum[i-1]-1;
		mn=min(mn,psum[i]);
	}
	if(psum[n]){
		printf("0\n1 1\n");
		return 0;
	}
	int ml=get_left(n,mn),mr=get_right(n,mn),sl=get_left(n,mn+1),sr=get_right(n,mn+1);
	while(ml>0 && s[ml]!=')') ml--;
	while(sl>0 && s[sl]!=')') sl--;
	while(mr<=n && s[mr]!='(') mr++;
	while(sr<=n && s[sr]!='(') sr++;
	sl=min(sl,ml);
	sr=max(sr,mr);
	//printf("%d %d %d %d\n",ml,mr,sl,sr);
	int al=1,ar=1,og=calc(1,1,n),ans=og;
	if(ml>0 && mr<=n && calc(ml,mr,n)>ans){
		ans=calc(ml,mr,n);
		al=ml;
		ar=mr;
	}
	if(sl>0 && sr<=n && calc(sl,sr,n)>ans){
		ans=calc(sl,sr,n);
		al=sl;
		ar=sr;
	}
	int mp=0,sp=0,sc=0,tc=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='('){
			if(psum[i-1]==mn) mp=i,sc=0;
			if(psum[i-1]==mn+1) sp=i,tc=0;
		}
		else{
			if(psum[i]==mn){
				if(sc>ans && mp>0){
					al=mp;
					ar=i;
					ans=sc;
				}
				mp=0;
			}
			if(psum[i]==mn+1){
				if(og+tc>ans && sp>0){
					al=sp;
					ar=i;
					ans=og+tc;
				}
				sp=0;
			}
		}
		if(mp>0 && psum[i]==mn+1) sc++;
		if(sp>0 && psum[i]==mn+2) tc++;
	}
	printf("%d\n%d %d\n",ans,al,ar);
	return 0;
}