#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;
const int maxn=1e5+123;
int n,a[maxn],cnt,l,r,m;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++) 
			if(a[j]>a[i])
				cnt++;
	cin>>m;
	while(m--){
		cin>>l>>r;
		l=r-l+1;
		l=l*(l-1)/2;
		if(l%2==1)
			cnt++;
		if(cnt%2)          
			cout<<"odd"<<endl;
		else
			cout<<"even"<<endl;

	}
}