#include <iostream>
#include <cmath>
using namespace std;
int main(){
	string str;
	getline(cin,str);
	getline(cin,str);
	int ne[2]={};
	for(auto i : str)
		++ne[i-'0'];
	cout<<max(ne[0],ne[1])-min(ne[0],ne[1])<<endl;
}