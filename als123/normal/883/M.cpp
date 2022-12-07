#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
int x,y,X,Y;
int main()
{
	scanf("%d %d %d %d",&x,&y,&X,&Y);
	if(x>X) swap(x,X);if(y>Y) swap(y,Y);
	if(x!=X&&y!=Y) printf("%d",(X-x+1)*2+(Y-y+1)*2);
	else if(x==X) printf("%d",(X-x+2)*2+(Y-y+1)*2);
	else printf("%d",(X-x+1)*2+(Y-y+2)*2);
}