#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);
using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	int n=63;
	long long int a[63]={0};
	a[0]=1;
	for(int i=1;i<n;i++){
		a[i]=a[i-1]*2;
	}
	vector<string> vs;
	int g[63]={0};
	string b="",c="$$$$$$$$$$$$$$$$$$$$$$";
	for(int i=0;i<n;i++){
		while(a[i]>0){
			b+=(a[i]%10+'0');
			a[i]/=10;
		}
		g[i]=b.length();
		for(int j=0;j<g[i];j++){
			c[g[i]-j-1]=b[j];
		}
		vs.push_back(c);
		b="";
		c="$$$$$$$$$$$$$$$$$$$$$$";
	}
	/*
	for(int i=0;i<n;i++){
		cout << vs[i] << " " << g[i] << endl;
	}*/
	while(t--){
		string s;
		cin >> s;
		int ans=9999;
		for(int i=0;i<n;i++){
			int k=0;
			for(int l=0;l<s.length();l++){
				if(s[l]==vs[i][k]){
					k++;
				}
			}
			//cout << k << endl;
			if(s.length()-k+g[i]-k<ans){
				ans=s.length()-k+g[i]-k;
				//cout << i << endl;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}