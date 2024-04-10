#include<bits/stdc++.h>
#define ll long long
#define N
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
string s,cur;
vector<string> num,mun;
bool check(string x){
	if(x.length() == 0) return 0;
	rep(i,0,(int)x.length()-1) if(!isdigit(x[i])) return 0;
	if(x[0] == '0' && x.length() != 1) return 0;
	return 1;
}
void print(vector<string> uuu){
	if(uuu.size() == 0) puts("-");
 	else{
 		putchar('"');
 		rep(i,0,SZ(uuu)-1){
 			cout << uuu[i] << (i==SZ(uuu)-1?'"':',');
 		}
 		cout << endl;
 	}
}
int n;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	cin >> s;
 	s += ',';
 	n = s.length();
 	rep(i,0,n-1){
 		if(s[i] == ';' || s[i] == ','){
 			if(check(cur)) num.pb(cur);
 			else mun.pb(cur);
 			cur = "";
 		}else{
 			cur += s[i];
 		}
 	}
 	print(num);
 	print(mun);
	return 0;
}