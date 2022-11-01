#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
ll tool(char xt[]){ll p=0;for(int i=0;xt[i]!=0;i++)p++;return p;}
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<"\n";}
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,m,ans;
ll a[110],b[110];
bool mark[110];

bool find(ll x)
{
	int p1=-1,p2=-1;
	for(int i=0;b[i]!=0;i++)
	{
		if(mark[i]==false)
		{
		if(b[i]==x-1)
		{
			mark[i]=true;
			return 1;
		}
			
		else if(b[i]==x)
			p1=i;
		else if(b[i]==x+1)
			p2=i;
			
		}
	}
	if(p1!=-1)
	{
		mark[p1]=true;
		return 1;
	}
	if(p2!=-1)
	{
		mark[p2]=true;
		return 1;
	}
	return 0;
		
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>m;
	for(int i=0;i<m;i++)
		cin>>b[i];	
	sort(a,a+n);
	
	for(int i=0;i<n;i++)
	{
		
		if(find(a[i])==true)
			ans++;
	}
	cout<<ans<<endl;
	
    return 0;
}