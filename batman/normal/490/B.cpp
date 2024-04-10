#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define INF (1000*1000*1000)
#define N (1000*1001)
#define ll long long
ll tool(char xt[]){ll p=0;for(int i=0;xt[i]!=0;i++)p++;return p;}
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<"\n";}
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,first,last;
ll q[N],p[N];



int main()
{
	cin>>n;
	ll ex,ex2;
	for(int i=0;i<n;i++)
	{
		cin>>ex>>ex2;
		p[ex]++;
		p[ex2]--;
		q[ex]=ex2;
		
	}
	int i,j=q[0];
	for(i=0;p[i]!=1;i++);
		
		
	while(j!=0 && i!=0)
	{
		cout<<i<<" "<<j<<" ";
		i=q[i];
		j=q[j];
	}
	if(i!=0)
		cout<<i<<endl;
    return 0;
}