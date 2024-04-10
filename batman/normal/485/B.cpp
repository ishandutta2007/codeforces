#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
#define f(i,first,last) for(int i=first;i<last;i++)
#define N (1000+100)
#define Max (1000*1000*1000)
#define LL long long int
ifstream fin("input.txt");
ofstream fout("output.txt");

LL n,x[N],y[N],minx,maxx,miny,maxy,xxx;

LL ghadr(LL x)
{
	LL x2=x;
		
	if(x<0)
		x2=(-1)*x;

	return x2;					
}

LL minim(LL xt[])
{
	LL min=Max;
	for(int i=0;i<n;i++)
		if(xt[i]<min)
			min=xt[i];
	return min;			
}

LL maxim(LL xt[])
{
	LL max=(-Max);
	for(int i=0;i<n;i++)
		if(xt[i]>max)
			max=xt[i];
	return max;			
}

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
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>x[i]>>y[i];
		
	minx=minim(x);
	maxx=maxim(x);
	miny=minim(y);
	maxy=maxim(y);
	
	xxx=max(maxx-minx,maxy-miny);
	cout<<xxx*xxx<<endl;
	
	
	
		
	
	
    return 0;
}