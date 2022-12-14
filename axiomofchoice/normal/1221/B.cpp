#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) \
	for(int i=(a),i##end=(b);i<i##end;i++)
int n;
int main(){
	//ios_base::sync_with_stdio(false);\
	cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	repeat(i,0,n){
		repeat(j,0,n){
			if((i^j)&1)cout<<'W';
			else cout<<'B';
		}
		cout<<endl;
	}
	return 0;
}