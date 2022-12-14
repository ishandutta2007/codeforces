#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define maxn 1000010
int t,f[26];
string s;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>s;
		mst(f,0);
		s='#'+s+'$';
		repeat(i,1,s.size()-1){
			int j=i;
			while(s[j]==s[i])j++;
			if((j-i)%2==1) 
				f[s[i]-'a']=1;
			i=j-1;
		}
		repeat(i,'a','z'+1)
		if(f[i-'a'])cout<<char(i);
		cout<<endl;
	}
	return 0;
}