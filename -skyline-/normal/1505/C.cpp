#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
string s;
int a[20],n;
int main(){
	cin>>s;
	n=s.size();
	for(int i=0;i<n;++i)a[i]=s[i]-65;
	for(int i=2;i<n;++i){
		if((a[i-1]+a[i-2])%26!=a[i]){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
    return 0;
}