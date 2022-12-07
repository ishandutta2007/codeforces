#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
int n,cnt;
bool ok;
string s;
int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i] == '?'){
			if(i==0 || i==n-1 || s[i-1] == s[i+1] || s[i-1] == '?'){
				ok = true;
			}
		}else if(i && s[i] == s[i-1]){
			puts("No");
			return 0;
		}
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}