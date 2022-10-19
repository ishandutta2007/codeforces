#include <iostream>

#define M 77
#define p 1000000007LL
#define f first
#define s second
#define mp make_pair
#define long long long

using namespace std;

long n,a=0,b=0,k,c[M][M],d[2][M][M],w[2][M][M];
bool u[2][M][M];

struct tem{
	pair<long,pair<long,long> > a[M*M];
	long s,f;
	void clear(){
		s=f=0;
	}
	void push(pair<long,pair<long,long> > x){
		a[f++]=x;
	}
	void pop(){
		s++;
	}
	pair<long,pair<long,long> > top(){
		return a[s];
	}
	bool empty(){
		return s==f;
	}
} q;

void pre(void){
	for (int i=0; i<M; ++i)
	c[i][0]=1;
	for (int i=1; i<M; ++i)
	for (int j=1; j<M; ++j){
		c[i][j]=c[i-1][j-1]+c[i-1][j];
		c[i][j]%=p;
	}
}

void read(void){
	cin>>n>>k;
	k/=50;
	for (int i=0,x; i<n; ++i){
		cin>>x;
		if (x==100)
		b++;
		else
		a++;
	}
}

void bfs(void){
	q.push(mp(0,mp(a,b)));
	w[0][a][b]=1;
	u[0][a][b]=1;
	d[0][a][b]=0;
	while (!q.empty()){
		long x=q.top().s.f;
		long y=q.top().s.s;
		long t=q.top().f;
		q.pop();
		for (long i=0; i<=x; ++i)
		for (long j=0; j<=y && i+2*j<=k; ++j)
		if (i+j>0){
			long x1=a-x+i;
			long y1=b-y+j;
			long t1=1-t;
			if (!u[t1][x1][y1]){
				q.push(mp(t1,mp(x1,y1)));
				u[t1][x1][y1]=1;
				d[t1][x1][y1]=d[t][x][y]+1;
			}
			if (d[t][x][y]+1==d[t1][x1][y1]){
				long bon;
				bon=c[x][i]*c[y][j];
				bon%=p;
				bon*=w[t][x][y];
				bon%=p;
				w[t1][x1][y1]+=bon;
				w[t1][x1][y1]%=p;
			}
		}
	}
	if (!u[1][a][b]){
		cout<<"-1\n0\n";
		return;
	}
	cout<<d[1][a][b]<<"\n";
	cout<<w[1][a][b]<<"\n";
}

int main()
{
	pre();
	read();
	bfs();
	return 0;
}