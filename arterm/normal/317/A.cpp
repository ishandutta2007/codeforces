#include <iostream>

#define long long long

using namespace std;

int main()
{
	long x,y,m,a=0,k;
	cin>>x>>y>>m;
	if (x>=m || y>=m){
		cout<<"0\n";
		return 0;
	}
	if (x<=0 && y<=0){
		cout<<"-1\n";
		return 0;
	}
	if (x<=0)
	swap(x,y);
	
	if (y<=0){
		k=(-y)/x;
		a+=k;
		y+=(k*x);
	}
	
	while (x<m && y<m){
		if (x<y)
		swap(x,y);
		y+=x;
		a++;
	}
	
	cout<<a<<"\n";
	
	return 0;
}