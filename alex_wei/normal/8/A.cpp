#include<bits/stdc++.h>
using namespace std;
string s,a,b;int c,d,e,f,l;
int main(){
	cin>>s>>a>>b,e=s.find(a),l=a.size();c=e!=-1&&s.find(b,e+l)!=-1;
	reverse(s.begin(),s.end());f=s.find(a);d=f!=-1&&s.find(b,f+l)!=-1;
	if(c&&d)puts("both");else if(c)puts("forward");else if(d)puts("backward");else puts("fantasy");
}