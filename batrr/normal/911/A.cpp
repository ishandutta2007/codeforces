#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;
const int maxn=1e5+123;
int n,ans=1e9;
pair<int,int> a[maxn];
int main(){                                                  
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].f;
		a[i].s=i;
	}
	sort(a,a+n);
	for(int i=1;i<n;i++)
		if(a[i].f==a[i-1].f)
			ans=min(ans,abs(a[i].s-a[i-1].s));
		else
			break;
	 cout<<ans;

}