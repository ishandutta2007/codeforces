#include <iostream>
#include <algorithm>

#define M 100100
#define long long long
#define INF 40000000000LL
#define f first
#define s second
#define mp make_pair

using namespace std;

pair<long,long> p[M],pr[M],su[M];
long n,s[M],f[M];

void read(void){
	cin>>n;
	for (long i=0,x,y; i<n; ++i){
		cin>>x>>y;
		p[i]=mp(x+y,x-y);
	}
	
	sort(p,p+n);
	
	for (int i=0; i<n; ++i)
	s[i]=2*p[i].f,f[i]=2*p[i].s;	
}

pair<long,long> comb(pair<long,long> a, pair<long,long> b){
	return mp(max(a.f,b.f),min(a.s,b.s));
}

bool good(pair<long,long> a){
	return a.f<=a.s;
}

bool pos(long t){
	pr[0]=mp(-t+f[0], t+f[0]);
	
	for (int i=1; i<n; ++i)
	pr[i]=comb(pr[i-1],mp(-t+f[i], t+f[i]));
	
	su[n-1]=mp(-t+f[n-1], t+f[n-1]);
	
	for (int i=n-2; i>=0; --i)
	su[i]=comb(su[i+1],mp(-t+f[i], t+f[i]));
	
	for (int i=0; i<n; ++i){
		int r=n-1,l=i,m;
		
		while (l<r){
			m=(l+r)/2;
			if (s[m+1]<=2*t+s[i])
			l=m+1;
			else
			r=m;
		}
		
		//cout<<i<<" beats "<<l<<"!\n";
		
		pair<long,long> po=mp(-10*INF,10*INF);
		if (i>0)
		po=comb(po,pr[i-1]);
		if (l+1<n)
		po=comb(po,su[l+1]);
		if (good(po))
		return 1;
		
	}
	return 0;
}

void kill(void){
	long l=0,r=INF,m;
	while (l<r){
		m=(l+r)/2;
		if (pos(m))
		r=m;
		else
		l=m+1;
	}
	cout.precision(10);
	cout<<fixed<<0.5*l<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
	kill();	
	return 0;
}