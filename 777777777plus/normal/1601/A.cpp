#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T;
int n,a[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int t=0;
		for(int j=0;j<30;++j){
			int c=0;
			for(int i=1;i<=n;++i)if(a[i]&1<<j)++c;
			t=__gcd(t,c);
		}
		vector<int> ans;
		if(!t){
 			for(int i=1;i<=n;++i)ans.push_back(i);
		}
		else{
			for(int i=1;i<=t;++i)
			if(t%i==0){
				ans.push_back(i);
			}
		}
		for(int i=0;i<ans.size();++i)printf("%d ",ans[i]);
		printf("\n");
	}
}