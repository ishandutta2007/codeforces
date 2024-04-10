#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
#define N (1100)
int n;
char move1[N][N],move2[N][N];
int a[N][N][2],dp1[N][N][2],dp2[N][N][2];
pair <int,int> point;
bool pntmrk;
int main()
{ 
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    	for(int j=0;j<n;j++)
    	{
    		int tmp;
    		scanf("%d",&tmp);
    		if(tmp==0)
    			point={i,j},a[i][j][0]=1,a[i][j][1]=1,pntmrk=1;
    		else
			{
				for(;!(tmp&1);tmp>>=1)a[i][j][0]++;
				for(;!(tmp%5);tmp/=5)a[i][j][1]++;	
			}	
    		
    	}
    dp1[n-1][n-1][0]=a[n-1][n-1][0];
	dp1[n-1][n-1][1]=a[n-1][n-1][1];
	dp2[n-1][n-1][0]=a[n-1][n-1][0];
	dp2[n-1][n-1][1]=a[n-1][n-1][1];		
    for(int i=n-2;i>=0;i--)
    {
    	dp1[i][n-1][0]=dp1[i+1][n-1][0]+a[i][n-1][0];
		dp1[i][n-1][1]=dp1[i+1][n-1][1]+a[i][n-1][1];
		dp2[i][n-1][0]=dp2[i+1][n-1][0]+a[i][n-1][0];
		dp2[i][n-1][1]=dp2[i+1][n-1][1]+a[i][n-1][1];
    	move1[i][n-1]=move2[i][n-1]='D';
    }
	for(int i=n-2;i>=0;i--)
	{
		dp1[n-1][i][0]=dp1[n-1][i+1][0]+a[n-1][i][0];
		dp1[n-1][i][1]=dp1[n-1][i+1][1]+a[n-1][i][1];
		dp2[n-1][i][0]=dp2[n-1][i+1][0]+a[n-1][i][0];
		dp2[n-1][i][1]=dp2[n-1][i+1][1]+a[n-1][i][1];
		move1[n-1][i]=move2[n-1][i]='R';
	}
	for(int i=n-2;i>=0;i--)
		for(int j=n-2;j>=0;j--)
		{
			int minim[2];
			if(dp1[i+1][j][0]<dp1[i][j+1][0])
				minim[0]=i+1,minim[1]=j,move1[i][j]='D';
			else
				minim[0]=i,minim[1]=j+1,move1[i][j]='R';	
			dp1[i][j][0]=dp1[minim[0]][minim[1]][0]+a[i][j][0],dp1[i][j][1]=dp1[minim[0]][minim[1]][1]+a[i][j][1];
			
			if(dp2[i+1][j][1]<dp2[i][j+1][1])
				minim[0]=i+1,minim[1]=j,move2[i][j]='D';
			else
				minim[0]=i,minim[1]=j+1,move2[i][j]='R';	
			dp2[i][j][0]=dp2[minim[0]][minim[1]][0]+a[i][j][0],dp2[i][j][1]=dp2[minim[0]][minim[1]][1]+a[i][j][1];
		}   
	int ans1=min(dp1[0][0][0],dp1[0][0][1]),ans2=min(dp2[0][0][0],dp2[0][0][1]);
	string s="";
	if(ans1>=1 && ans2>=1 && pntmrk)
	{
		int x=0,y=0;
		cout<<"1\n";
		while(x!=point.first || y!=point.second)
		{
			if(x<point.first)
				s+='D',x++;
			else
				s+='R',y++;	
		}
		while(x!=n-1 || y!=n-1)
		{
			if(x<n-1)
				s+='D',x++;
			else
				s+='R',y++;	
		}
		
	}
	else if(ans1<ans2)
	{
		printf("%d\n",ans1);
		int x=0,y=0;
		while(x!=n-1 || y!=n-1)
		{
			s+=move1[x][y];
			if(move1[x][y]=='D')
				x++;
			else
				y++;	
		}
	}
	else
	{
		printf("%d\n",ans2);
		int x=0,y=0;
		while(x!=n-1 || y!=n-1)
		{
			s+=move2[x][y];
			if(move2[x][y]=='D')
				x++;
			else
				y++;	
		}
	}
	cout<<s;	
	return 0;
}