#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define INF (1000*1000*1000)
#define N 
#define ll long long
ll tool(char xt[]){ll p=0;for(int i=0;xt[i]!=0;i++)p++;return p;}
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<"\n";}
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ifstream fin("input.txt");
ofstream fout("output.txt");


bool check(int x)
{
	if(x==0)
		return 0;
	if(x<0)
		x*=(-1);
	while(x>0)
	{
		if(x%10==8)
			return 1;
		x/=10;	
	}
	return 0;		
}


int main()
{
	ll a;
	cin>>a;
	for(ll i=a+1,p=1;;i++,p++)
	{
		if(check(i)==true)
		{
			cout<<p<<endl;
			return 0;
		}
	}
	
	
    return 0;
}