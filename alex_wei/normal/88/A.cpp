#include<bits/stdc++.h>
using namespace std;
//
string x[3];
map <string,int> c;
bool cmp(string a,string b){return c[a]<c[b];}
int i,j,k,l;
int main()
{
	c["C"]=1,c["C#"]=2,c["D"]=3,c["D#"]=4,c["E"]=5,c["F"]=6,c["F#"]=7,c["G"]=8,c["G#"]=9,c["A"]=10,c["B"]=11,c["H"]=12;
	cin>>x[0]>>x[1]>>x[2];
	sort(x,x+3,cmp);
	i=c[x[0]],j=c[x[1]],k=c[x[2]];
	if(k-i==7&&j-i==4&&k-j==3)cout<<"major",exit(0);
	if(k-i==7&&j-i==3&&k-j==4)cout<<"minor",exit(0);
	i+=12,l=i,i=j,j=k,k=l;
	if(k-i==7&&j-i==4&&k-j==3)cout<<"major",exit(0);
	if(k-i==7&&j-i==3&&k-j==4)cout<<"minor",exit(0);
	k-=12,l=k,k=j,j=i,i=l;
	k-=12,l=k,k=j,j=i,i=l;
	if(k-i==7&&j-i==4&&k-j==3)cout<<"major",exit(0);
	if(k-i==7&&j-i==3&&k-j==4)cout<<"minor",exit(0);
	cout<<"strange";
	return 0;
}