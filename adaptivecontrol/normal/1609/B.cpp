#include<bits/stdc++.h>
using namespace std;
int n,q,cnt;
int main(){
	string s;
	cin>>n>>q>>s;
	for(int i=2;i<s.size();i++)
		if(s[i-2]=='a'&&s[i-1]=='b'&&s[i]=='c')
			cnt++;
	while(q--){
		int pos;
		char c;
		scanf("%d",&pos);
		cin>>c;
		pos--;
		for(int i=pos;i<min(int(s.size()),pos+3);i++)
			if(s[i-2]=='a'&&s[i-1]=='b'&&s[i]=='c')
				cnt--;
		s[pos]=c;
		for(int i=pos;i<min(int(s.size()),pos+3);i++)
			if(s[i-2]=='a'&&s[i-1]=='b'&&s[i]=='c')
				cnt++;
		printf("%d\n",cnt);
	}
}