#include<bits/stdc++.h>
#define ll long long
#define N
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int t,n;
string s;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	cin>>t;
 	while(t--){
 		cin>>n;
 		cin>>s;
 		int odd,even;odd = even = -1;
 		if(n&1){
 			rep(i,0,n-1){
 				if((i&1)==0){
 					int v = s[i]-'0';
 					if(v&1) odd = 1;
 					else even = 1;
 				}
 			}
 			if(odd != -1) puts("1");
 			else puts("2");
 		}else{
 			rep(i,0,n-1){
 				if((i&1)==1){
 					int v = s[i]-'0';
 					//cout << "v: " <<v << endl;
 					if(v&1) odd = 1;
 					else even = 1;
 				}
 			}
 			if(even != -1) puts("2");
 			else puts("1");
 		}

 	}
	return 0;
}