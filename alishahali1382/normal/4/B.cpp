#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=2000 * 1000 + 10;

int d, s, x, y;
int t1[31];
int t2[31];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>d>>s;
	for (int i=0; i<d; i++){
		cin>>t1[i]>>t2[i];
		x+=t1[i];
		y+=t2[i];
	}
	if (x>s || s>y){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	s-=x;
	for (int i=0; i<d; i++){
		if (t2[i]-t1[i]<=s){
			s-=t2[i]-t1[i];
			t1[i]=t2[i];
		}
		else {
			t1[i]+=s;
			s=0;
		}
		if (!s) break ;
	}
	for (int i=0; i<d; i++){
		cout<<t1[i]<<' ';
	}
	return 0;
}