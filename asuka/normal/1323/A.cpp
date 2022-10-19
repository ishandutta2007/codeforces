#include<bits/stdc++.h>
#define ll long long
#define N 105
using namespace std;
int t,n,a[N],p1,p2; 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		p1 = p2 = 0;
		for(int i = 1;i <= n;++i) cin>>a[i];
		if(n==1&&a[1]%2==1){
			puts("-1");
			continue;
		}
		for(int i = 1;i <= n;++i){
			if(a[i]%2==0){
				cout << "1" << endl;
				cout << i << endl;
				break;
			}else{
				if(p1==0) p1 = i;
				else{
					p2 = i;
					cout << "2" << endl;
					cout << p1 << ' ' << p2 << endl;
					break;
				}
			}
		}
	}
	return 0;
}