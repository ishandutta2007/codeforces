#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n,m;
	cin>>n;
	int l[n],r[n],ll[m],rr[m];
	for(int i=0;i<n;i++)
		cin>>l[i]>>r[i];
	cin>>m;
	for(int i=0;i<m;i++)
		cin>>ll[i]>>rr[i];
	sort(l,l+n);sort(r,r+n);sort(ll,ll+m);sort(rr,rr+m);
	cout<<max(0,max(l[n-1]-rr[0],ll[m-1]-r[0]));
	return 0;
}