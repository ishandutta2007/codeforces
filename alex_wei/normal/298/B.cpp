#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
string s;
int t,sx,sy,ex,ey; 
int main(){
	cin>>t>>sx>>sy>>ex>>ey>>s;
	for(int i=0;i<s.size();i++){
		int x=sx,y=sy;
		if(s[i]=='N')y++;
		if(s[i]=='W')x--;
		if(s[i]=='S')y--;
		if(s[i]=='E')x++;
		if(abs(x-ex)+abs(y-ey)<abs(sx-ex)+abs(sy-ey))sx=x,sy=y;
		if(x==ex&&y==ey)cout<<i+1<<endl,exit(0); 
	}
	puts("-1");
    return 0;
}