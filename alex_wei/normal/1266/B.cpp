#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
ll x;
int main(){
	cin>>t;
	while(t--){
		cin>>x;
		if(x<=14){
			puts("NO");
			continue;
		}
		ll r=x%14;
		if(r>0&&r<7)puts("YES");
		else puts("NO");
	}
    return 0;
}