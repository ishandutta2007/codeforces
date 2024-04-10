#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int query(vector<int>& a){
	cout << "? " << a.size() << " ";
	for(auto h:a){
		cout << h << " ";
	}
	cout << endl;
	string s;
	cin >> s;
	if(s=="NO"){
		return 0;
	}
	else{
		return 1;
	}
}
int ans(int a){
	cout << "! ";
	cout << a << endl;
	string s;
	cin >> s;
	if(s[1]=='('){
		return 0;
	}
	return 1;
}
int main(){
    //AquA;
	int n;
	cin >> n;
	vector<int> v(n);
	iota(v.begin(),v.end(),1);
	pair<int,int> lst;
	while(v.size()>3){
		int u=v.size();
		vector<int> z;
		for(int i=0;i<u/2;i++){
			z.push_back(v[i]);
		}
		int y=query(z);
		vector<int> c,rvc;
		if(y){
			int h=u-(u/2);
			for(int i=u/2;i<u/2+h/2;i++){
				c.push_back(v[i]);
			}
			for(int i=u/2+h/2;i<u;i++){
				rvc.push_back(v[i]);
			}
		}
		else{
			for(int i=0;i<(u/2)/2;i++){
				c.push_back(v[i]);
			}
			for(int i=(u/2)/2;i<u/2;i++){
				rvc.push_back(v[i]);
			}
		}
		vector<int> nr;
		int r=query(c);
		if(r==1){
			swap(c,rvc);
		}
		lst.fs=r;
		reverse(c.begin(),c.end());
		for(int i=0;i<u;i++){
			if(c.size() && v[i]==c.back()){
				c.pop_back();
				continue;
			}
			nr.push_back(v[i]);
		}
		v=nr;
		if(v.size()<=3){
			for(int i=0;i<3;i++){
				if(v[i]==rvc[0]){
					lst.sc=i;
				}
			}
		}
	}
	if(v.size()==1){
		ans(v[0]);
		return 0;
	}
	if(v.size()==2){
		int u=ans(v[0]);
		if(u==1){
			return 0;
		}
		ans(v[1]);
		return 0;
	}
	if(v.size()==3){
		vector<int> f(1,v[0]);
		int y=query(f);
		if(y==1){
			int u=ans(f[0]);
			if(u==1){
				return 0;
			}
			vector<int> p(1,v[1]);
			int z=query(p);
			if(z==1){
				ans(p[0]);
			}
			else{
				ans(v[2]);
			}
		}
		else{
			int b=query(f);
			if(b==1){
				int u=ans(f[0]);
				if(u==1){
					return 0;
				}
				vector<int> p(1,v[1]);
				int z=query(p);
				if(z==1){
					ans(p[0]);
				}
				else{
					ans(v[2]);
				}
				return 0;
			}
			else{
				ans(v[0]);
			}
			vector<int> p(1,v[1]);
			int u=query(p);
			int l=ans(v[0]);
			if(l==1){
				return 0;
			}
			if(u==1){
				ans(v[1]);
			}
			else{
				ans(v[2]);
			}
		}
	}
	
    return 0;
}