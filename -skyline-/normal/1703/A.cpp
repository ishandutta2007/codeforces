#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#define fi   first
#define se   second
using namespace std;
int T;
string s;
int main(){
	cin>>T;
	while(T--){
		cin>>s;
		if((s[0]=='y'||s[0]=='Y')&&(s[1]=='e'||s[1]=='E')&&(s[2]=='s'||s[2]=='S'))printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}