#include <iostream>

using namespace std;

#define M 550

int n,m,k;
char f[M][M];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool u[M][M];
bool ban[M][M];

bool in(int x, int y){
	return 0<=x && x<n && 0<=y && y<m;
}

void read(void){
	cin>>n>>m>>k;
	for (int i=0; i<n; ++i)
	for (int j=0; j<m; ++j)
	cin>>f[i][j];
}

void dfs(int x, int y){
	u[x][y]=1;
	for (int i=0; i<4; ++i){
		int x1=x+dx[i];
		int y1=y+dy[i];
		if (in(x1,y1) && !u[x1][y1] && f[x1][y1]!='#')
		dfs(x1,y1);
	}
	if (k>0){
		ban[x][y]=1;
		--k;
	}
}

int main()
{
	read();
	
	for (int i=0; i<n; ++i)
	for (int j=0; j<m; ++j)
	if (f[i][j]=='.' && !u[i][j])
	dfs(i,j);
	
	
	for (int i=0; i<n; ++i,cout<<"\n")
	for (int j=0; j<m; ++j)
	if (f[i][j]=='#')
	cout<<'#';
	else
	if (ban[i][j])
	cout<<'X';
	else
	cout<<'.';
	
	return 0;
}