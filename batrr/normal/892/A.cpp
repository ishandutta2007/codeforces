#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e6+1000;
long long n,a,s,b[maxn];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		s+=a;
	}
	for(int i=0;i<n;i++)
		cin>>b[i];
	sort(b,b+n);
	if(b[n-1]+b[n-2]<s)
		cout<<"NO";
	else
		cout<<"YES";
    return 0;
}