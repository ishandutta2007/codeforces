#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define M 100100
#define T 2002000
#define N 25

int p[N],a[M],c[N];
int n,m,d;
bool b[T];

void pre(void){
	p[0]=1;
	for (int i=1; i<N; ++i)
		p[i]=2*p[i-1];
}

void read(void){
	cin>>n>>m>>d;
	for (int i=0; i<m; ++i){
		int s;
		cin>>s;
		for (int j=0,x; j<s; ++j){
			cin>>x;
			a[x]=i;
		}
	}
}

void calc(void){
	for (int i=1; i<=d; ++i)
		c[a[i]]++;
	for (int i=d+1; i<=n+1; ++i){
		int x=0;
		for (int j=0; j<m; ++j)
			if (c[j]>0)
				x|=p[j];

		c[a[i-d]]--;
		c[a[i]]++;
		b[x]=1;
	}
}


void din(void){
	for (int i=1; i<p[m]; ++i)
		for (int j=0; j<m; ++j)
			b[i]|=((i&p[j])==p[j] && b[i^p[j]]);

	int ans=m;

	for (int i=0; i<p[m]; ++i)
		if (!b[i]){
			int t=0;
			for (int j=0; j<m; ++j)
				if ((i&p[j])==0)
					t++;
			ans=min(ans,t);
		}

	cout<<ans<<"\n";
				
}



int main(){
#ifdef TROLL
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#else
	ios_base::sync_with_stdio(0);
#endif
	pre();
	read();
	calc();
	din();

	return 0;
}