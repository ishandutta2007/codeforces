#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstring>
#define fastio cin.tie(0);ios_base::sync_with_stdio(false);cout.tie(0);
using namespace std;

int main(){
	fastio;
	string s;
	cin >> s;
	int n=s.length();
	vector<int> z(n);
	int maxx=0,maxf=0;
	z[0]=n;
	int l=0,r=0;
	for(int i=1;i<n;i++){
		if(i+z[i-l]<r){
			z[i]=z[i-l];
		}
		else{
			l=i;
			if(i>r){
				r=i;
			}
			while(r<n && s[r-l]==s[r]){
				r++;
			}
			z[i]=r-l;
		}
		if(z[i]>maxx){
			maxx=z[i];
			maxf=1;
		}
		else if(z[i]==maxx){
			maxf++;
		}
	}
	int ans=0;
	for(int i=1;i<n;i++){
		if(z[i]==n-i){
			if(maxx>n-i || (maxx==n-i && maxf>1)){
				ans=i;
				break;
			}
		}
	}
	if(ans!=0){
		for(int i=ans;i<n;i++){
			cout << s[i];
		}
		cout << endl;
	}
	else{
		cout << "Just a legend" << endl;
	}	
	return 0;
}