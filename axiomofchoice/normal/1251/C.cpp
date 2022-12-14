#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define maxn 1000010
int n,t;
vector<int> a[2];
string s;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>s;
		a[0].clear();
		a[1].clear();
		repeat(i,0,s.size()){
			a[s[i]%2].push_back(s[i]);
		}
		s="";
		int s0=0,s1=0;
		while(1){
			if(s0==a[0].size() && s1==a[1].size())break;
			if(s1==a[1].size())
				s+=char(a[0][s0++]);
			else if(s0==a[0].size())
				s+=char(a[1][s1++]);
			else if(a[0][s0]<a[1][s1])
				s+=char(a[0][s0++]);
			else
				s+=char(a[1][s1++]);
		}
		cout<<s<<endl;
	}
	return 0;
}