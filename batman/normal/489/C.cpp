#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define Max
#define N 
#define ll int
ll tool(char xt[]){ll p=0;for(int i=0;xt[i]!=0;i++)p++;return p;}
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<" ";}
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ifstream fin("input.txt");
ofstream fout("output.txt");

ll a,b;
char maxim[110],minim[110];


void karak(char &xt,ll x)
{
	if(x==0)
		xt='0';
	if(x==1)
		xt='1';
	if(x==2)
		xt='2';
	if(x==3)
		xt='3';
	if(x==4)
		xt='4';
	if(x==5)
		xt='5';
	if(x==6)
		xt='6';
	if(x==7)
		xt='7';
	if(x==8)
		xt='8';
	if(x==9)
		xt='9';	
										
}

void high()
{
	ll ex=b;
	for(ll i=0;i<a;i++)
	{
		if(ex<=9)
		{
			karak(maxim[i],ex);
			ex=0;
		}
			
		else
		{
			maxim[i]='9';
			ex-=9;
		}
				
	}
}

void down()
{
	ll ex=b;
	for(ll i=0;i<a;i++)
	{
		if((a-(i+1))*9>=ex && i>0)
			karak(minim[i],0);
			
		else if((a-(i+1))*9<ex)
		{
			karak(minim[i],ex-((a-(i+1))*9));
			ex-=ex-((a-(i+1))*9);
		}
			
			
		else if(i==0 && ex>0)
		{
			karak(minim[i],1);
			ex-=1;
		}
			
		else
		{
			karak(minim[i],9);
			ex-=9;
		}			
	}
}

int main()
{
	cin>>a>>b;
	if((a>1 && b==0) || b>(a*9) || a==0)
	{
		cout<<"-1 -1\n";
		return 0;
	}
	if(a==1 && b==0)
	{
		cout<<"0 0\n";
		return 0;
	}
	high();
	//prt(maxim);
	down();
	prt(minim);
	prt(maxim);
    return 0;
}