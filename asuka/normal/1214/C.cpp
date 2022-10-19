#include<bits/stdc++.h>
using namespace std;
string s;
int top,len,flag;
int main(){
	//freopen("my.out","w",stdout);
	//freopen("data.in","r",stdin);
	cin >> len >> s;
	for(int i = 0;i < len;++i){
		if(s[i]=='('){
			top++;
		}else{
			if(top==0) flag++;
			else top--;
		}
	}
	if((top==1&&flag==1)||(top==0&&flag==0)) cout << "Yes";
	else cout << "No";
    return 0;
}