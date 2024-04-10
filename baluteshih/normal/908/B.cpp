#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string map[50];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1},arr[4]={0,1,2,3},n,m;

bool check(int x,int y)
{
	if(x<0 || y<0 || x>=n || y>=m || map[x][y]=='#') return 0;
	return 1; 
}

int main()
{
	int i,j,ans=0,x,y,nx,ny,flag;
	string s;
	cin >> n >> m;
	for(i=0;i<n;i++)
	{
		cin >> map[i];
		for(j=0;j<m;j++)
			if(map[i][j]=='S') x=i,y=j;
	}
	cin >> s;
	do
	{
		for(i=0,nx=x,ny=y,flag=0;i<s.size();i++)
		{
			if(!check(nx+dx[arr[s[i]-'0']],ny+dy[arr[s[i]-'0']])) break;
			nx+=dx[arr[s[i]-'0']],ny+=dy[arr[s[i]-'0']];
			if(map[nx][ny]=='E')
			{
				flag=1;
				break;
			}
		}
		ans+=flag;
	}while(next_permutation(arr,arr+4));
	cout << ans << "\n";
}