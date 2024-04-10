#include<bits/stdc++.h>
#define ll long long
#define N 1015
using namespace std;
char s[N];
vector<int> L,R;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s",s);
	int len = strlen(s);
	int l = 0,r = len-1;
	while(l < r){
		while(l < r&&s[l] == ')') l++;
		while(l < r&&s[r] == '(') r--;
		if(l < r) L.push_back(l),R.push_back(r),l++,r--;
	}
	if(L.size()==0){
		cout << 0 << endl;
		return 0;
	}
	cout << 1 << endl;
	cout << L.size()+R.size() << endl;
	for(int i = 0;i < L.size();++i) cout << L[i]+1 << ' ';
	for(int i = (int)R.size()-1;i >= 0;--i) cout << R[i]+1 << ' ';
	return 0;
}