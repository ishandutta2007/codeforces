#include <bits/stdc++.h>
using namespace std;
int inp[40000];
void init(){
	inp[0]=inp[1]=1;
	for(int i=2;i<40000;){
		for(int j=i*2;j<=40000;j+=i) inp[j]=1;
		for(i++;i<40000 && inp[i];i++);
	}
}
void solve(){
	int n;
	cin >> n;
	int c1, c2;
	for(c1=1+n;inp[c1];c1++);
	for(c2=c1+n;inp[c2];c2++);
	cout << c1 * c2 << "\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int T;
	cin >> T;
	for(int i=0;i<T;i++) solve();
}