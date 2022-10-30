#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>

using namespace std;
typedef long long LL;

int Find(int l,int r)
{
	if (l>=r) return l;
	int mid=l+r>>1;
	cout<<1<<" "<<mid<<" "<<mid+1<<endl;
	fflush(stdout);
	string s;cin>>s;
	if (s=="TAK") return Find(l,mid);
	else return Find(mid+1,r);
}
int main()
{
	int n,K;cin>>n>>K;
	int x=Find(1,n);
	int y=x>1?Find(1,x-1):Find(x+1,n);
	cout<<1<<" "<<y<<" "<<x<<endl;
	fflush(stdout);
	string s;cin>>s;
	if (s=="TAK") cout<<2<<" "<<y<<" "<<x;
	else cout<<2<<" "<<x<<" "<<Find(x+1,n);
	fflush(stdout);
	return 0;
}