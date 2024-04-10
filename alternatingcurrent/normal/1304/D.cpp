#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n;
string s;
int a[200200];
int b[200200];

int main(){
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		cin >> s;
		int i = 0, pre = 0, already = 1;
		while(i < n-1){
			i++;
			while(i < n-1 && s[i] == s[i-1]) i++;
//			if(i == n-1) i++;
			int st = already;
			if(s[pre] == '>'){
				for(int j = i; j >= pre; j--) a[j] = st++;
			} else {
				if(pre == 0) pre--;
				if(i == n-1) i++;
				for(int j = pre+1; j < i; j++) a[j] = st++;
			}
			pre = i;
			already = st;
		}
		i = 0, pre = 0, already = n;
		while(i < n-1){
			i++;
			while(i < n-1 && s[i] == s[i-1]) i++;
//			if(i == n-1) i++;
			int st = already;
			if(s[pre] == '<'){
				for(int j = i; j >= pre; j--) b[j] = st--;
			} else {
				if(pre == 0) pre--; 
				if(i == n-1) i++;
				for(int j = pre+1; j < i; j++) b[j] = st--;
			}
			pre = i;
			already = st;
		}
		rep(j, n) cout << b[j] << " "; cout << endl; 
		rep(j, n) cout << a[j] << " "; cout << endl;
	}
	return 0;
}