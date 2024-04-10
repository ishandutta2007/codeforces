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
string s;
ll ans;
int main(){
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
		if(s[i]=='Q')
			for(int j=i+1;j<n;j++)
				if(s[j]=='A')
					for(int q=j+1;q<n;q++)
						if(s[q]=='Q')
							ans++;
	cout<<ans;
	return 0; 
}