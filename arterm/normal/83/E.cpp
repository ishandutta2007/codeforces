#include <iostream>
#include <string>
#include <algorithm>

#define M 2100200
#define N 21
#define K 200200

using namespace std;

int p[N],d[M],a[K],n,m,h,b[K];
string s[K];

void pre(void){
	p[0]=1;
	for (int i=1; i<N; ++i)
	p[i]=p[i-1]<<1;
}

void read(void){
	cin>>n;
	for (int i=0; i<n; ++i)
	cin>>s[i];
	
	m=s[0].length();
	
	for (int i=0; i<n; ++i)
	for (int j=0; j<m; ++j)
	a[i]+=(s[i][j]=='1' ? p[j]:0);	
}

void calc(void){
	int p[2*K];
	string t;
	p[0]=0;
	h=m;
	for (int k=1; k<n; ++k){
		t=s[k]+"#"+s[k-1];
		
		for (int i=1; i<=2*m; ++i){
			int j=p[i-1];
		
			while (j>0 && t[j]!=t[i])
			j=p[j-1];
		
			if (t[j]==t[i])
			j++;
		
			p[i]=j;
		}
		b[k]=m-p[2*m];
		h+=b[k];
	}
}

void kill(void){
	
	for (int i=0; i<M; ++i)
	d[i]=M;
	
	d[1]=0;
	
	
	for (int i=1; i<n; ++i){
		
		int x=m+1;
		for (int j=0; j<=m; ++j)
		x=min(x,d[(a[i]&(p[j]-1))|p[j]]+m-j);
		
		x-=b[i];
		
		for (int j=0; j<=m; ++j){
			int to=(a[i-1]>>(m-j))|p[j];
			d[to]=min(d[to],x);
		}
	}
	
	cout<<*min_element(d,d+M)+h<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	pre();
	read();
	calc();
	kill();
	return 0;
}