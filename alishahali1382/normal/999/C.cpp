#include <iostream>
#include <queue>

using namespace std;

int out[400000+10];

int main(){
	int n,k;
	string s;
	cin>>n>>k;
	cin>>s;
	queue<int> L[26];
	int i=0;
	for (auto it=s.begin();it!=s.end();it++){
		L[(*it)-'a'].push(i);
		i++;
	}
	i=0;
	while (k){
		if (L[i].empty()) i++;
		else{
			out[L[i].front()]=1;
			L[i].pop();
			k--;
		}
	}
	i=0;
	for (auto it=s.begin();it!=s.end();it++){
		if (!out[i]) cout<<(*it);
		i++;
	}
	cout<<endl;
	
	
	return 0;
}