#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s; int k;
int main(){
	cin>>s>>k;
	for(int i=0;i<s.size()-1;i++){
		int f=min(i+k,(int)s.size()-1);
		int pos=i;
		for(int j=i+1;j<=f;j++)
			if(s[j]>s[pos])
				pos=j;
		k-=pos-i;
		for(int j=pos;j>i;j--)
			swap(s[j],s[j-1]);
	}
	cout<<s<<endl;
    return 0;
}