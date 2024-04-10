#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
int p1=1,p2=2,n,a;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a==6-p1-p2){
			cout<<"NO";
			return 0;
		}
		if(a==p1)
			p2=6-p1-p2;
		else
			p1=6-p1-p2;
	}
	cout<<"YES";
	return 0; 
}