#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define Max
#define N 3100
#define ll long long
ll tool(char xt[]){ll p=0;for(int i=0;xt[i]!=0;i++)p++;return p;}
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<"\n";}
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,a[N];
vector <pair <int,int> > v;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		int ex=i;
		for(int j=i+1;j<n;j++)
			if(a[ex]>a[j])
				ex=j;
		if(ex!=i)
			v.push_back(make_pair(ex,i));
		swap(a[ex],a[i]);		
	}
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++)
		cout<<v[i].first<<" "<<v[i].second<<endl;
		
	
	
    return 0;
}