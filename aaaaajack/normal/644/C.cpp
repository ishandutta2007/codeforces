#include<bits/stdc++.h>
#define N 100100
using namespace std;
pair<string,string> p[N];
map<string,vector<string> > m; 
char s[100];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		int t=7;
		while(s[t]&&s[t]!='/') t++;
		p[i].second=string(s+t);
		s[t]=0;
		p[i].first=string(s);
	}
	sort(p,p+n);
	n=unique(p,p+n)-p;
	string tmp;
	for(int i=0;i<n;i++){
		if(i&&p[i].first!=p[i-1].first){
			m[tmp].push_back(p[i-1].first);
			tmp=string();
		}
		tmp+="$"+p[i].second;
	}
	m[tmp].push_back(p[n-1].first);
	for(auto it=m.begin();it!=m.end();){
		if(it->second.size()==1) it=m.erase(it);
		else ++it;
	}
	printf("%d\n",m.size());
	for(auto it=m.begin();it!=m.end();++it){
		for(auto x:it->second){
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}