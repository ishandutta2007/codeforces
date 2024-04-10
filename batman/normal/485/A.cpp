#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define f(i,first,last) for(int i=first;i<last;i++)
#define N 
#define LL long long int
ifstream fin("input.txt");
ofstream fout("output.txt");

int tool(char xt[])
{
	int p=0;
	for(int i=0;xt[i]!=0;i++)
		p++;
	return p;	
}

void prt(char xt[])
{
	for(int i=0;xt[i]!=0;i++)
		cout<<xt[i];
	cout<<"\n";	
}


int main()
{
	LL a,m;
	cin>>a>>m;
	
	for(int i=0;i<100*1000;i++)
	{
		a+=a%m;
		if(a%m==0)
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
    return 0;
}