#include<bits/stdc++.h>
using namespace std;
int n,s;
string r;
map <string,int> c; 
int main()
{
	c["Tetrahedron"]=4;
	c["Cube"]=6;
	c["Octahedron"]=8;
	c["Dodecahedron"]=12;
	c["Icosahedron"]=20;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>r,s+=c[r];
	cout<<s;
    return 0;
}