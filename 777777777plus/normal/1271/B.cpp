#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e3+5;

int n,a,b;
string s;
vector<int>A,B,ans;

int main(){
	cin>>n>>s;
	for(int i=0;i<n;++i)
	if(s[i]=='B')a++,A.push_back(i);
	else b++,B.push_back(i);
	if((a&1)&&(b&1)){
		puts("-1");
		return 0;
	}
	vector<int>&t=(A.size()&1)?B:A;
	for(int i=0;i<t.size();i+=2){
		int x=t[i],y=t[i+1];
		for(int j=x;j<y;++j)ans.push_back(j);
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();++i)cout<<ans[i]+1<<" ";
}