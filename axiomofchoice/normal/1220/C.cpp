#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) \
for(int i=(a),i##end=(b);i<i##end;i++)
string s;
int main(){
	//ios_base::sync_with_stdio(false);
	cin>>s;
	int n=s.length();
	int m=255;
	repeat(i,0,n){
		if(m>=s[i]){
			cout<<"Mike\n";
		}
		else{
			cout<<"Ann\n";
		}
		m=min(m,(int)s[i]);
	}
	return 0;
}