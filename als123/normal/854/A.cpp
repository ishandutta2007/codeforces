#include <bits/stdc++.h>
using namespace std;
int N; int gcd(int x,int y){return (y==0)?x:gcd(y,x%y);}
int main()
{
  scanf("%d",&N); double maxx=0.0; int x,y;
  for(int i=N-1;i>=1;i--) if(gcd(i,N-i)==1 && i<(N-i))
  {
	double p=(double)i/(double)(N-i);
	if(p>maxx) maxx=p,x=i,y=N-i;
  }
  return printf("%d %d\n",x,y),0;
}