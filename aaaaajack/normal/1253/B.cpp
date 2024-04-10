#include<bits/stdc++.h>
using namespace std;
int main(){
	set<int> s,p;
	int x,n;
	cin>>n;
	vector<int> d;
	bool flag=true;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(x<0){
			auto it=s.find(-x);
			if(it==s.end()){
				flag=false;
				break;
			}
			s.erase(it);
		}
		else{
			auto it=s.find(x);
			if(it!=s.end()){
				flag=false;
				break;
			}
			it=p.find(x);
			if(it!=p.end()){
				flag=false;
				break;
			}
			s.insert(x);
			p.insert(x);
		}
		if(s.empty()){
			p.clear();
			d.push_back(i+1);
		}
	}
	if(!s.empty()) flag=false;
	if(flag){
		printf("%d\n",(int)d.size());
		for(int i=0;i<d.size();i++){
			if(i) putchar(' ');
			printf("%d",d[i]-(i?d[i-1]:0));
		}
		puts("");
	}
	else{
		puts("-1");
	}
	return 0;
}