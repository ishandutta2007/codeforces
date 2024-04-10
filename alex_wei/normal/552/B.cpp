#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
ll n,bs=1,ans;
int main(){
	cin>>n;
	for(int i=1;i<=15;i++){
		bs*=10;
		if(n<bs){
			ans+=i*(n-bs/10+1);
			break;
		}
		else ans+=i*bs/10*9;
	}
	cout<<ans<<endl;
    return 0;
}