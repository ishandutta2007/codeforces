#include <iostream>
#include <set>

using namespace std;

int main(){
	int n;
	cin>>n;
	int w[n];
	set<pair<int,int>> st1;
	set<pair<int,int>> st2;
	
	for (int i=0;i<n;i++){
		cin>>w[i];
		st2.insert(pair<int,int> (w[i],i));
	}
	char c;
	for (int i=0;i<2*n;i++){
		cin>>c;
		if (c=='0'){
			auto it=st2.begin();
			auto x=*it;
			cout<<x.second+1<<' ';
			st1.insert(pair<int,int> (-x.first,x.second));
			st2.erase(it);
		}
		else{
			auto it=st1.begin();
			auto x=*it;
			cout<<x.second+1<<' ';
			st1.erase(it);
		}
	}
	cout<<endl;
	return 0;
}