#include <iostream>
#include <vector>
#include <queue>
#define pb push_back
using namespace std;
const int maxn=1e6+123;
long long  a[maxn],n,ans,sum,pre[maxn];
queue<int>q;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		pre[i]=pre[i-1]+a[i];
	}
	if(sum%3!=0){
		cout<<0;
		return 0;
	}else
		sum/=3;
	for(int i=1;i<n-1;i++)
		if(pre[i]==sum*2)
			q.push(i);
	for(int i=0;i<n-1;i++){
		if(!q.empty() && q.front()<=i)
			q.pop();
		if(pre[i]==sum)
			ans+=q.size();
		//cout<<i<<" "<<pre[i]<<" "<<ans<<" "<<q.size()<<endl;
	}
	cout<<ans;
}