#include <bits/stdc++.h>
#define lg long
#define ll lg lg
#define ull unsigned ll
using namespace std;

int main(){
    ull n, x,q;
    cin>>n>>q;
	while (q--){
		cin>>x;
		while (x%2==0) x=x/2+n;
		cout<<(x+1)/2<<endl;
	}
}