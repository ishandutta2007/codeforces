#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
using namespace std;
char a[100],rl,keyboard[30]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l',';','z','x','c','v','b','n','m',',','.','/'};
int rl2;



void calc()
{
	for(int i=0;a[i]!=0;i++)
	{
		for(int j=0;j<30;j++)
			if(a[i]==keyboard[j])
			{
				a[i]=keyboard[j+rl2];
				break;
			}			
	}
}

int main() {
	ifstream fin ("input.txt");
	
	cin>>rl>>a;
	
	if(rl=='R')
		rl2=(-1);
	if(rl=='L')
		rl2=1;	
	
	calc();
	
	for(int i=0;a[i]!=0;i++)
		cout<<a[i];
	cout<<"\n";
	
	return 0;
}