#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e3+5;
ll n,p[N],q[N],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		p[x+y]++,q[x-y+1000]++;
	}
	for(int i=1;i<N;i++)ans+=p[i]*(p[i]-1)/2+q[i]*(q[i]-1)/2;
	cout<<ans<<endl;
    return 0;
}