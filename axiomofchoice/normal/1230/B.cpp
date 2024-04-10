#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) \
	for(int i=(a),i##end=(b);i<i##end;i++)
#define mst(a,x) memset(a,x,sizeof(a))
int n,k;
string s;
int main(){
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>k;
	cin>>s;
	if(n>=2)
	repeat(i,0,n){
		if(k<=0)break;
		if(i==0){
			if(s[i]=='1'){
			}
			else{
				s[i]='1';
				k--;
			}
		}
		else{
			if(s[i]=='0'){
			}
			else{
				s[i]='0';
				k--;
			}
		}
	}
	if(n==1 && k>=1)s[0]='0';
	cout<<s<<endl;
	return 0;
}