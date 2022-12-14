#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) \
	for(int i=(a),i##end=(b);i<i##end;i++)

vector<int> a;
bool fun(int x,int y){return x>y;}
bool work(){
	while(1){
		if(a.empty())return false;
		if(a.size()==1)return a[0]==2048;
		sort(a.begin(),a.end(),fun);
		if(a.back()==2048)return true;
		if(a[a.size()-1]==a[a.size()-2]){
			a.pop_back();
			a.back()*=2;
		}
		else{
			a.pop_back();
		}
	}
}
int main(){
	//ios_base::sync_with_stdio(false);\
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin>>N;
	while(N--){
		int n,x;
		cin>>n;
		a.clear();
		repeat(i,0,n){
			cin>>x;
			if(x>2048)continue;
			a.push_back(x);
		}
		if(work())cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}