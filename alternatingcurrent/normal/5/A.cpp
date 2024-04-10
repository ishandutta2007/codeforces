#include<bits/stdc++.h>
using namespace std;
char c[111];
int main(){
	int cnt = 0;
	int ans = 0;
	while(gets(c) && c[0] != '@'){
		if(c[0] == '+') cnt++;
		else if(c[0] == '-') cnt--;
		else{
			int i = 0;
			while(c[i] != ':') i++;
			i++;
			int Lenth = strlen(c) - i;
			ans += cnt * Lenth;
		}
	}
	cout << ans << endl;
	return 0;
}