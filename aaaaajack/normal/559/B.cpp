#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<utility>
#define N 200100
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	int i,j,q=s1.size(),p=0;
	vector<int> v1,v2,tv1,tv2;
	pair<int,int> tmp;
	vector<pair<int,int> > rk;
	vector<string> ori;
	while(q%2==0){
		q>>=1;
		p++;
	}
	for(i=0;i<s1.size();i+=q){
		ori.push_back(s1.substr(i,q));
		ori.push_back(s2.substr(i,q));
	}
	sort(ori.begin(),ori.end());
	ori.resize(unique(ori.begin(),ori.end())-ori.begin());
	for(i=0;i<s1.size();i+=q){
		v1.push_back(lower_bound(ori.begin(),ori.end(),s1.substr(i,q))-ori.begin());
		v2.push_back(lower_bound(ori.begin(),ori.end(),s2.substr(i,q))-ori.begin());
	}
	for(i=0;i<p;i++){
		for(j=0;j<v1.size();j+=2){
			if(v1[j]<v1[j+1]) rk.push_back(make_pair(v1[j],v1[j+1]));
			else rk.push_back(make_pair(v1[j+1],v1[j]));
			if(v2[j]<v2[j+1]) rk.push_back(make_pair(v2[j],v2[j+1]));
			else rk.push_back(make_pair(v2[j+1],v2[j]));
		}
		sort(rk.begin(),rk.end());
		rk.resize(unique(rk.begin(),rk.end())-rk.begin());
		tv1.clear();
		tv2.clear();
		for(j=0;j<v1.size();j+=2){
			if(v1[j]<v1[j+1]) tv1.push_back(lower_bound(rk.begin(),rk.end(),make_pair(v1[j],v1[j+1]))-rk.begin());
			else tv1.push_back(lower_bound(rk.begin(),rk.end(),make_pair(v1[j+1],v1[j]))-rk.begin());
			if(v2[j]<v2[j+1]) tv2.push_back(lower_bound(rk.begin(),rk.end(),make_pair(v2[j],v2[j+1]))-rk.begin());
			else tv2.push_back(lower_bound(rk.begin(),rk.end(),make_pair(v2[j+1],v2[j]))-rk.begin());
		}
		v1=tv1;
		v2=tv2;
	}
	if(v1[0]==v2[0]) puts("YES");
	else puts("NO");
	return 0;
}