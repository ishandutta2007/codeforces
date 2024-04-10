#include <iostream>
#include <string>
#include <set>

#define M 210
#define long long long

using namespace std;

long n,l[M],r[M],d[M][M][M],t[M],len;
string s,p[M];
set<string> se;

void read(void){
	cin>>s;
	cin>>n;
	len=s.length();
	for (int i=0; i<n; ++i)
	cin>>p[i]>>l[i]>>r[i],t[i]=p[i].length();
}

void din(void){
	for (int i=0; i<n; ++i)
	for (int l=0; l<len; ++l)
	for (int r=l; r<len; ++r){
		if (r-l+1<t[i])
		d[i][l][r]=0;
		else
		d[i][l][r]=d[i][l][r-1];
		if (s.substr(r-t[i]+1,t[i])==p[i])
		d[i][l][r]++;
	}
}

bool good(int i,string s){
	int k=0;
	int len=s.length();
	for (int j=0; j+len<=t[i]; ++j)
	if (p[i].substr(j,len)==s)
	k++;
	return l[i]<=k && k<=r[i];
}

void kill(void){
	for (int i=0; i<len; ++i)
	for (int j=i; j<len; ++j){
		bool flag=1;
		for (int y=0; y<n; ++y)
		if (!good(y,s.substr(i,j-i+1))){
			flag=0;
			break;
		}
		if (flag)
		se.insert(s.substr(i,j-i+1));
		
	}
	cout<<se.size()<<"\n";
}

int main()
{
	read();
	//din();
	kill();
	return 0;
}