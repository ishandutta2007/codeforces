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

int main()
{
	ll a[5500],n;
	vector <ll> v1,v2,v3,n1,n2,n3;
	

	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			v1.push_back(i);
		if(a[i]==2)
			v2.push_back(i);
		if(a[i]==3)
			v3.push_back(i);		
	}
	ll min=INF;
	if(v1.size()<min)
		min=v1.size();
	if(v2.size()<min)
		min=v2.size();
	if(v3.size()<min)
		min=v3.size();	
	cout<<min<<endl;
	for(int i=0;i<min;i++)
	{
		cout<<v1[i]+1<<" "<<v2[i]+1<<" "<<v3[i]+1<<endl;
	}		
	
    return 0;
}