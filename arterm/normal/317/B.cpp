#include <iostream>

#define M 500
#define N 100
#define f first
#define s second
#define mp make_pair
#define S 270000

using namespace std;

int a[M][M],n,h=0,t=0,dx[]={1,-1,0,0},dy[]={0,0,1,-1},ma=N;
pair<int,int> p[S];
bool u[M][M];

void kill(void){
	cin>>n;
	a[N][N]=n;
	p[t++]=mp(N,N);
	while (h!=t){
		int x=p[h].f,y=p[h].s;
		
		h++;
		if (h==S)
		h=0;
		
		int k=a[x][y]/4;
		a[x][y]-=(4*k);
		u[x][y]=0;
		for (int i=0; i<4; ++i){
			int x1=x+dx[i],y1=y+dy[i];
			a[x1][y1]+=k;
			if (x1>=2*N){
				cout<<"Palundra!\n";
				return ;
			}
			ma=max(ma,x1);
			if (!u[x1][y1] && a[x1][y1]>=4){
				u[x1][y1]=1;
				p[t]=mp(x1,y1);
				t++;
				if (t==S)
				t=0;
			}
		}
	}
	
}

void bull(void){
	int t,x,y;
	cin>>t;
	while (t--){
		cin>>x>>y;
		x+=N,y+=N;
		if (x<=0 || y<=0 || M<=x || M<=y){
			cout<<"0\n";
			continue;
		}
		cout<<a[x][y]<<"\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	kill();
	bull();
	return 0;
}