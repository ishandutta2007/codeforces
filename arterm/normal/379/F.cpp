#include <iostream>

using namespace std;

#define M 1000200
#define N 23

int n=4,f[N],s[N],c[M],deep[N],ans[N];
int d[M];
int p[M][N];


void pre(void){
	for (int i=2; i<=4; ++i){
		c[i]=i;
		f[i]=s[i]=i;
		deep[i]=1;
		d[i]=1;
		ans[i]=0;
		
		for (int j=0; j<N; ++j)
		p[i][j]=i;
	}
}

void calc(int x){
	for (int i=1; i<N; ++i)
	p[x][i]=p[p[x][i-1]][i-1];
}

int pred(int x, int k){
	int i=0;
	while (k){
		if (k&1)
		x=p[x][i];
		k>>=1;
		++i;
	}
	return x;
}

int dist(int x, int y){
	if (d[x]<d[y])
	swap(x,y);
	
	
	
	int b=d[x]-d[y];
	int l=0,r=n,m;
	while (l<r){
		m=(l+r)/2;
		if (pred(x,m+b)==pred(y,m))
		r=m;
		else
		l=m+1;
	}
	
	return 2*l+b;
}

void add(int v){
	int l=n+1,r=n+2,col=c[v];
	n+=2;
	c[r]=c[l]=col;
	d[l]=d[r]=d[v]+1;
	p[l][0]=p[r][0]=v;
	
	calc(l);
	calc(r);
	
	//cout<<col<<": "<<f[col]<<"-"<<s[col]<<"\n";
	//cout<<ans[col]<<"..."<<dist(f[col],s[col])<<"\n";
	
	if (deep[col]>=d[l]){
		int di=dist(f[col],l);
		if (di>ans[col]){
			ans[col]=di;
			s[col]=l;
		}
	}
	else{
		++deep[col];
		int dif=dist(f[col],l);
		int dis=dist(s[col],l);
		int dir=2;
		if (dir>max(dif,dis)){
			f[col]=l;
			s[col]=r;
			ans[col]=2;
		}
		else
		if (dif>dis){
			ans[col]=dif;
			s[col]=f[col];
			f[col]=l;
		}
		else{
			ans[col]=dis;
			f[col]=l;
		}
	}
		
}

void prnt(void){
	int a=0;
	for (int i=2; i<=4; ++i)
	a=max(a,ans[i]);
	
	for (int i=2; i<4; ++i)
	for (int j=i+1; j<=4; ++j)
	a=max(a,deep[i]+deep[j]);
	cout<<a<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	pre();
	int q;
	cin>>q;
	for (int i=0,x; i<q; ++i){
		cin>>x;
		add(x);
		prnt();
	}
	return 0;
}