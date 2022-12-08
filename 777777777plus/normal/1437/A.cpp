#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
ll l,r;

int main(){
	cin>>T;
	while(T--){
		cin>>l>>r;
		if(l>r/2)puts("YES");
		else puts("NO");
	}
}