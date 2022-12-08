#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e3+5;

int T;
int n,k;
char s[N];
vector<pair<int,int> >ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		ans.clear();
		for(int i=1,c=0;i<=n;++i)
		if(s[i]=='('){
			++c;
			ans.push_back(make_pair(c,i));
			reverse(s+c,s+i+1);
		}
		for(int i=1;i<k;++i){
			int ed=n/2+i;
			ans.push_back(make_pair(ed-n/2+i,ed));
		}
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();++i)printf("%d %d\n",ans[i].first,ans[i].second);
	}
}