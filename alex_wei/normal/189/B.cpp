#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll w,h,ans;
int main(){
	cin>>w>>h;
	for(int i=1;i<=w/2;i++)for(int j=1;j<=h/2;j++)ans+=(w-i*2+1)*(h-j*2+1);
	cout<<ans<<endl;
    return 0;
}