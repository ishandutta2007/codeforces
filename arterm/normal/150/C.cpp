#include <iostream>

#define M 150100
#define INF 1000000000000LL
#define long long long

using namespace std;

struct data{
	long l,r,a,s;
} t[4*M];

long x[M],p[M],n,a[M],m,c;

data ini(long val){
	data a;
	a.l=a.r=a.a=(val>0 ? val:0);
	a.s=val;
	return a;
}

data comb(data l, data r){
	data z;
	z.l=max(l.l,(l.s+r.l));
	z.r=max(r.r,(r.s+l.r));
	z.s=l.s+r.s;
	z.a=max(max(l.a,r.a),(l.r+r.l));
	return z;
}

void make(int v, int l, int r){
	if (l==r){
		t[v]=ini(a[l]);
		return;
	}
	int m=(l+r)/2;
	make(2*v,l,m);
	make(2*v+1,m+1,r);
	t[v]=comb(t[2*v],t[2*v+1]);
}

data que(int v, int l, int r, int le, int re){
	if (le==l && re==r)
	return t[v];
	int m=(l+r)/2;
	
	if (re<=m)
	return que(2*v,l,m,le,re);
	if (m+1<=le)
	return que(2*v+1,m+1,r,le,re);
	
	return comb(que(2*v,l,m,le,m),
			que(2*v+1,m+1,r,m+1,re));
}

void read(void){
	cin>>n>>m>>c;
	for (int i=0; i<n; ++i)
	cin>>x[i];
	for (int i=1; i<n; ++i)
	cin>>p[i];
	for (int i=1; i<n; ++i)
	a[i]=100*(x[i]-x[i-1])-2*c*p[i];
}

void kill(void){
	make(1,1,n-1);
	long ans=0;
	for (int i=0,l,r; i<m; ++i){
		cin>>l>>r;
		r--;
		ans=ans+que(1,1,n-1,l,r).a;
		//cout<<"I think, "<<que(1,1,n-1,l,r).a<<" is maximum\n";
	}
	cout<<(double)ans/200<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.precision(9);
	cout<<fixed;
	read();
	kill();	
	return 0;
}