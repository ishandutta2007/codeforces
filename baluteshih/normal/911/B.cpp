#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,a,b,x,tmp,p;
	for(cin >> n >> a >> b,x=(a+b)/n;x>0;x--)
	{
		if(a<x || b<x) continue;
		for(tmp=a,p=n;p>0 && tmp>=x;p--)
			tmp-=x;
		for(tmp=b;p>0 && tmp>=x;p--)
			tmp-=x;
		if(p==0) break;
	}
	cout << x << "\n";
}