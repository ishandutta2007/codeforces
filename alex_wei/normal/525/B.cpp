#include<bits/stdc++.h>
using namespace std;
string s; int m,buc[200005],a;
int main(){
	cin>>s>>m;
	for(int i=1;i<=m;i++)cin>>a,buc[a]^=1;
	for(int i=1;i<=s.size();i++){
		int p=min(i,(int)s.size()-i+1);
		if(buc[p])cout<<s[s.size()-i];
		else cout<<s[i-1]; buc[i+1]^=buc[i];
	}
    return 0;
}