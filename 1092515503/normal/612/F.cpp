#include<bits/stdc++.h>
using namespace std;
int n,m,p,a[2010],f[2010],g[2010],F[2010],G[2010],res=0x3f3f3f3f;//f:the minimal starting from i; g:the minimal ending at i
vector<int>v[2010],u;
stack<int>s;
int main(){
	scanf("%d%d",&n,&p),p--,memset(f,0x3f,sizeof(f)),memset(g,0x3f,sizeof(g));
	for(int i=0;i<n;i++)scanf("%d",&a[i]),u.push_back(a[i]);
	sort(u.begin(),u.end()),u.resize(m=unique(u.begin(),u.end())-u.begin());
	for(int i=0;i<n;i++)v[a[i]=lower_bound(u.begin(),u.end(),a[i])-u.begin()+1].push_back(i);
//	for(int i=0;i<n;i++)printf("%d ",a[i]);puts("");
//	for(int i=1;i<=m;i++){for(auto j:v[i])printf("%d ",j);puts("");}
	for(auto i:v[1])f[i]=min((i+n-p)%n,(p+n-i)%n),F[i]=-1;
	for(int i=1;i<=m;i++){
		int len=v[i].size();
		for(int j=0;j<len;j++)for(int k=0;k<len;k++){
			if(j==k)continue;
			int J=v[i][j],K=v[i][k];
			int A=(v[i][(k+len-1)%len]+n-J)%n*2+(J+n-K)%n;
			int B=(J+n-v[i][(k+1)%len])%n*2+(K+n-J)%n;
			if(g[K]>f[J]+min(A,B))g[K]=f[J]+min(A,B),G[K]=J;
		}
		if(len==1)g[v[i][0]]=f[v[i][0]],G[v[i][0]]=v[i][0];
		if(i==m)continue;
		for(auto j:v[i])for(auto k:v[i+1])if(f[k]>g[j]+min((k+n-j)%n,(j+n-k)%n))f[k]=g[j]+min((k+n-j)%n,(j+n-k)%n),F[k]=j;
	}
//	for(int i=0;i<n;i++)printf("%d ",f[i]);puts("");
//	for(int i=0;i<n;i++)printf("%d ",g[i]);puts("");
	for(auto i:v[m])res=min(res,g[i]);
	printf("%d\n",res);
	for(auto K:v[m]){
		if(g[K]!=res)continue;
		for(int i=m;i;i--){
			int len=v[i].size();
			int J=G[K];
			int j=lower_bound(v[i].begin(),v[i].end(),J)-v[i].begin(),k=lower_bound(v[i].begin(),v[i].end(),K)-v[i].begin();
			int A=(v[i][(k+len-1)%len]+n-J)%n*2+(J+n-K)%n;
			int B=(J+n-v[i][(k+1)%len])%n*2+(K+n-J)%n;
			if(len>1){
				if(A<B){
					for(int l=k;(l+1)%len!=j;(++l)%=len)s.push(-(v[i][(l+1)%len]+n-v[i][l])%n);
					s.push(-(v[i][(k+len-1)%len]+n-v[i][(j+len-1)%len])%n);
					for(int l=(k+len-1)%len;l!=j;(l+=len-1)%=len)s.push((v[i][l]+n-v[i][(l+len-1)%len])%n);
				}else{
					for(int l=k;(l+len-1)%len!=j;(l+=len-1)%=len)s.push((v[i][l]+n-v[i][(l+len-1)%len])%n);
					s.push((v[i][(j+1)%len]+n-v[i][(k+1)%len])%n);
					for(int l=(k+1)%len;l!=j;(++l)%=len)s.push(-(v[i][(l+1)%len]+n-v[i][l])%n);
				}				
			}
			A=J,B=F[J];
			if(B==-1)B=p;
			s.push((A+n-B)%n<(B+n-A)%n?(A+n-B)%n:-(B+n-A)%n);
			K=B;
		}
		break;
	}
//	auto S=s;while(!S.empty())printf("%d ",(p+=S.top()+n)%n),S.pop();puts("");
	while(!s.empty())printf("%c%d\n",(s.top()>=0?'+':'-'),abs(s.top())),s.pop();
	return 0;
}