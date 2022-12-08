#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n,m,k;

struct ex{
	int f;string s;
};

vector<ex>ans;
vector<ex>res;

int main(){
	cin>>n>>m>>k;
	if(k>4*n*m-2*n-2*m){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	ans.push_back({n-1,"D"});
	for(int i=1;i<=n-1;++i){
		ans.push_back({m-1,"RUD"});
		ans.push_back({m-1,"L"});
		ans.push_back({1,"U"}); 
	}
	ans.push_back({m-1,"R"});
	ans.push_back({m-1,"L"});
	for(int i=0;i<ans.size();++i){
		ex step=ans[i];
		if(k>step.s.size()*step.f){
			if(step.f)res.push_back({step.f,step.s});
			k-=step.s.size()*step.f;
		}
		else{
			step.f=k/step.s.size();
			if(step.f)res.push_back({step.f,step.s});
			if(k%step.s.size()){
				string temp;
				for(int j=0;j<k%step.s.size();++j)temp+=step.s[j];
				res.push_back({1,temp});
			}
			break;
		}
	}
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();++i){
		cout<<res[i].f<<" "<<res[i].s<<endl;
	}
}