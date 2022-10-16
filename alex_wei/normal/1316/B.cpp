#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
struct node{
	int id; string s;
	bool operator < (const node &v) const {
		return s<v.s||s==v.s&&id<v.id;
	}
}c[5005];
int main(){
	cin>>t;
	while(t--){
		string s;
		int n;
		cin>>n>>s;
		for(int i=1;i<=n;i++){
			c[i].s="",c[i].id=i;
			int bg=(n-i)&1?0:i-1;
			for(int j=0;j<n;j++){
				int pos=j+i-1;
				if(pos<n)c[i].s+=s[pos];
				else c[i].s+=s[(n-i)&1?bg++:--bg];
			}
		}
		sort(c+1,c+n+1);
		cout<<c[1].s<<"\n"<<c[1].id<<endl;
	}
	return 0;
}