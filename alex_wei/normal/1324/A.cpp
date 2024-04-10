#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,a[105];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		int x=0,y=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]&1)x=1;
			else y=1;
		}
		if(x&&y)puts("NO");
		else puts("YES");
	}
    return 0;
}