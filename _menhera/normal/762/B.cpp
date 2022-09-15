#include<bits/stdc++.h>
using namespace std;
int usb, ps2, both;
vector<int> u;
vector<int> p;
vector<int> b;
int main()
{
	scanf("%d%d%d",&usb,&ps2,&both);
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		int x; char k[99];
		scanf("%d%s",&x,k);
		if(k[0]=='U') u.push_back(x);
		else p.push_back(x);
	}
	int a1=0;
	long long a2=0;
	sort(u.begin(), u.end());
	for(int i=0; i<usb && i<u.size(); i++)
	{
		a1++;
		a2 += u[i];
	}
	sort(p.begin(), p.end());
	for(int i=0; i<ps2 && i<p.size(); i++)
	{
		a1++;
		a2 += p[i];
	}
	for(int i=usb; i<u.size(); i++)
		b.push_back(u[i]);
	for(int i=ps2; i<p.size(); i++)
		b.push_back(p[i]);
	sort(b.begin(), b.end());
	for(int i=0; i<both && i<b.size(); i++)
	{
		a1++;
		a2 += b[i];
	}
	printf("%d %lld\n",a1, a2);
	return 0;
}