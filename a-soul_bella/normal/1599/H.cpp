#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;
const int inf=1e9; 
signed main() {
	int n;
	cout<<"? "<<1<<' '<<1<<endl;
	int d1,d2,d3,d4;
	cin>>d1;
	cout<<"? "<<1<<' '<<inf<<endl;
	cin>>d2; 
	cout<<"? "<<inf<<' '<<1<<endl;
	cin>>d3;
	cout<<"? "<<inf<<' '<<inf<<endl;
	cin>>d4;
	int l=1,r=inf,ans=inf;
	while (l<=r) {
		int mid=(l+r)>>1; 
		cout<<"? "<<1<<' '<<mid<<endl;
		int dd;
		cin>>dd;
		ans=min(ans,dd); 
		if (abs(d1-dd)==abs(1-mid) && abs(d2-dd)==abs(inf-mid)) {
			ans=dd; break; 
		}
		else if (abs(d1-dd)==abs(1-mid)){
			l=mid+1; 
		}
		else if (abs(d2-dd)==abs(inf-mid)) {
			r=mid-1; 
		}
		else {
			ans=dd; break ; 
		}
	}
	
	int x=1+ans;
	int y=d1+2-x;
	int p=d3-inf+1-y; p=-p; 
	int q=2*inf-p-d4;
	cout<<"! "<<x<<' '<<y<<' '<<p<<' '<<q<<endl; 
	//system("PAUSE"); 
	return 0; 
}