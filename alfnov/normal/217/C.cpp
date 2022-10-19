//qwq
#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int L[1000005],R[1000005];
int ys(int a,int b,char c){
	if(c=='&')return a&b;
	if(c=='|')return a|b;
	if(c=='^')return a^b;
	return -1;
}
int f(int l,int r){
	if(l>r)return 6;
	if(l==r){
		if(s[l]=='?')return 6;
		if(s[l]=='0')return 1;
		if(s[l]=='1')return 8;
		return -1;
	}
	if(R[l]==r)return f(l+1,r-1);
	int wz,A,B;
	if(s[l]=='(')wz=R[l]+1,A=f(l,wz-1),B=f(wz+1,r);
	else wz=l+1,A=f(l,wz-1),B=f(wz+1,r);
	int ans=0;
	for(int i=0;i<4;++i)for(int j=0;j<4;++j){
		if(!(A&(1<<i)))continue;
		if(!(B&(1<<j)))continue;
		int I0=(i>=2),I1=(i&1);
		int J0=(j>=2),J1=(j&1);
		ans|=1<<(ys(I0,J0,s[wz])<<1|ys(I1,J1,s[wz]));
	}
	return ans;
}
int main(){
	int n,m;
	cin>>m;
	scanf("%s",s+1);
	n=strlen(s+1);
	stack<int>st;
	for(int i=1;i<=n;++i){
		if(s[i]=='(')st.emplace(i);
		else if(s[i]==')'){
			int ll=st.top();
			st.pop();
			R[ll]=i,L[i]=ll;
		}
	}
	if(f(1,n)&6)printf("YES\n");
	else printf("NO\n");
	return 0;
}