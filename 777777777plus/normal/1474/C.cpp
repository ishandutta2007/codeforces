#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e3+5;

int T;
int n;
int a[N];
multiset<int> s;
vector<pair<int,int>> ans;

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=2*n;++i)cin>>a[i];
		sort(a+1,a+2*n+1);
		bool ex=0;
		for(int i=1;i<2*n;++i){
			int x=a[2*n];
			bool flag=1;
			s.clear();
			ans.clear();
			ans.push_back({a[i],a[2*n]});
			for(int j=1;j<2*n;++j)
			if(j!=i){
				s.insert(a[j]);
			}
			for(int j=1;j<n;++j){
				int r=*s.rbegin();
				s.erase(s.find(r));
				if(s.find(x-r)==s.end()){
					flag=0;
					break;
				}
				s.erase(s.find(x-r));
				ans.push_back({x-r,r});
				x=r;
			}
			if(flag){
				ex=1;
				break;
			}
		}
		if(ex){
			puts("YES");
			printf("%d\n",ans[0].first+ans[0].second);
			for(int i=0;i<ans.size();++i){
				printf("%d %d\n",ans[i].first,ans[i].second);
			}
		}
		else{
			puts("NO");
		}
	}
}