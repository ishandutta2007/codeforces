#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,r,g,b;
int main(){
	cin>>t;
	while(t--){
		cin>>r>>g>>b;
		if(r>g)swap(r,g);
		if(g>b)swap(g,b);
		if(r>g)swap(r,g);
		if(g>b)swap(g,b);
		if(r+g>=b-1)puts("Yes");
		else puts("No");
	}
    return 0;
}