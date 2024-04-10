#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define Max
#define N (150)
#define ll long long
ll tool(char xt[]){ll p=0;for(int i=0;xt[i]!=0;i++)p++;return p;}
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<"\n";}
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ifstream fin("input.txt");
ofstream fout("output.txt");

bool mat[N][N],mark[N][N];
ll m,n,p;
int main()
{
	cin>>m>>n;

	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>mat[i][j];
			if(mat[i][j]==0)
			{
				for(int q=1;q<=n;q++)		
					mark[i][q]=true;	
				for(int q=1;q<=m;q++)
					mark[q][j]=true;			
			}
		}
		
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			p=0;
			if(mat[i][j]==1)
			{
				for(int q=1;q<=n;q++)		
					if(mark[i][q]==false)
						p++;
				for(int q=1;q<=m;q++)
					if(mark[q][j]==false)
						p++;
				if(p==0)
				{
					cout<<"NO"<<endl;
					return 0;
				}		
			}
			
		}
		
	cout<<"YES"<<endl;	
		
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mark[i][j]==true)
				cout<<0<<" ";
			else
				cout<<1<<" ";	
		}
		cout<<endl;
	}
			
			
	
	
    return 0;
}