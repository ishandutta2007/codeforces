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
int nxt[26],n,k;
string s;
void fuck(){
	cout << s;
	exit(0);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> n >> k;
	while(1){
		rep(i,0,k-1){
			s += i+'a';
			if((int)s.length() == n) fuck();
 			rep(j,i+1,k-1){
 				
 				s += i+'a';
 				
 				if((int)s.length() == n) fuck();
 				s += j+'a';
 				if((int)s.length() == n) fuck();
 			}
 		}
	}
 	
	return 0;
}